#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>

template <typename T>
class Queue	// 원형 큐. 나머지 연산을 사용해 배열의 처음과 끝이 이어져 있는 것 처럼 사용
{
	public:
		Queue(int capacity = 2)
		{
			assert(capacity > 0);

			this->capacity_ = capacity;
			this->queue_ = new T[capacity];
			this->front_ = 0;
			this->rear_ = 0;
		}

		~Queue()
		{
			if (this->queue_ == nullptr) 
				return ;
			delete[] this->queue_;
		}

		bool IsEmpty() const
		{
			// front 인덱스는 가장 첫 인덱스의 이전 공간을 의미,
			// rear 인덱스는 가장 마지막 공간을 의미.
			// 따라서 front == rear이면 데이터가 없는 상태
			return this->front_ == this->rear_;
		}

		bool IsFull() const
		{
			// 원형 큐에서 꽉 찼다의 기준
			return (this->rear_ + 1) % capacity_ == this->front_;
		}

		T& Front() const
		{
			assert(!IsEmpty());

			return this->queue_[(this->front_ + 1) % capacity_]; // 주의 + 1
		}

		T& Rear() const
		{
			assert(!IsEmpty());

			return this->queue_[this->rear_];
		}

		int Size() const
		{
			// 나머지 연산의 특징 이용: 같은 값으로 나누면 나머지에 반영되지 않는다.
			// 일반적인 상황은 rear > front. 문제가 되는 상황은 front > rear인 상황이다.
			// front > rear에서 (rear - front) % capactiy를 하면 음수가 나올 수 있으므로, 
			// (rear - front + capacity) % capacity를 사용한다.
			// abs(rear - front) < capacity이므로, rear - front + capacity는 양수가 보장된다!
			return (this->rear_ - this->front_ + capacity_) % capacity_;
		}

		void Resize() // 2배씩 증가
		{
			int new_capacity = this->capacity_ * 2;
			T* new_queue = new T[new_capacity];

			int front = 0, rear = 0;
			if (this->front_ < this->rear_)
			{
				// 간단한 케이스. front와 rear 사이에 있는 요소들을 복사
				rear = this->rear_ - this->front_ - 1;
				memcpy(&(new_queue[1]), &(this->queue_[this->front_ + 1]), sizeof(T) * rear);	// front는 0이므로 실제 데이터는 1부터 시작
				rear += 1 + 1;
			}
			else if (this->front_ > this->rear_)
			{
				// (1) front ~ capacity까지의 요소를 복사
				rear = this->capacity_ - this->front_ - 1;
				memcpy(&(new_queue[1]), &(this->queue_[this->front_ + 1]), sizeof(T) * rear);	// front는 0이므로 실제 데이터는 1부터 시작
				// (2) 0 ~ rear까지의 요소를 복사
				// 새로운 queue의 rear 위치를 갱신하는 순서에 주의.
				// front ~ capacity까지 복사한 이후 인덱스부터 0 ~ rear까지니까 복사 이후에 rear 위치를 갱신해야 함!
				memcpy(&(new_queue[rear + 1 + 1]), this->queue_, sizeof(T) * this->rear_);
				rear += this->rear_ + 1 + 1;
			}

			this->capacity_ = new_capacity;
			this->front_ = front;
			this->rear_ = rear;
			delete[] this->queue_;
			this->queue_ = new_queue;
		}

		void Enqueue(const T& item) // 맨 뒤에 추가, Push()
		{
			if (IsFull())
				Resize();
			
			this->rear_ = (this->rear_ + 1) % capacity_;
			this->queue_[this->rear_] = item;
		}

		void Dequeue() // 큐의 첫 요소 삭제, Pop()
		{
			assert(!IsEmpty());

			this->front_ = (this->front_ + 1) % capacity_;
		}

		void Print()
		{
			using namespace std;

			for (int i = (this->front_ + 1) % capacity_; i != (this->rear_ + 1) % capacity_; i = (i + 1) % capacity_)
				cout << this->queue_[i] << " ";
			cout << endl;

			if (print_debug_)
				PrintDebug();
		}

		void PrintDebug()
		{
			using namespace std;

			cout << "Cap = " << capacity_ << ", Size = " << Size();
			cout << endl;

			// front와 rear 위치 표시
			for (int i = 0; i < capacity_; i++) {
				if (i == this->front_) cout << " F ";
				else if (i == this->rear_) cout << " R ";
				else cout << "   ";
			}
			cout << endl;

			// 0 based index
			for (int i = 0; i < capacity_; i++)
				cout << setw(2) << i << " ";
			cout << endl;

			if (this->front_ < this->rear_)
			{
				// front 앞 사용하지 않은 공간
				for (int i = 0; i < this->front_ + 1; i++)
					cout << " - ";

				// 저장된 내용물
				for (int i = this->front_ + 1; i <= this->rear_; i++)
					cout << setw(2) << this->queue_[i] << " ";

				// rear 뒤 사용하지 않은 공간
				for (int i = this->rear_ + 1; i < capacity_; i++)
					cout << " * ";

				cout << endl << endl;
			}
			else if (this->front_ > this->rear_)
			{
				// rear 이전에 저장된 내용물
				for (int i = 0; i <= this->rear_; i++)
					cout << setw(2) << this->queue_[i] << " ";

				// rear와 front 사이 사용하지 않은 공간
				for (int i = this->rear_ + 1; i <= this->front_; i++)
					cout << " * ";

				// front 뒤 내용물
				for (int i = this->front_ + 1; i < capacity_; i++)
					cout << setw(2) << this->queue_[i] << " ";

				cout << endl << endl;
			}
			else // 비었을 경우
			{
				for (int i = 0; i < capacity_; i++)
					cout << " - ";
				cout << endl << endl;
			}
		}

		void SetDebugFlag(bool flag)
		{
			this->print_debug_ = flag;
		}

	private:
		T* queue_ = nullptr;
		int front_ = 0;
		int rear_ = 0;
		int capacity_ = 0;
		bool print_debuf_ = false;	
};