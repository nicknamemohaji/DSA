#include <iostream>
#include <cstring>

class MyString
{
    public:
        MyString(void);
        MyString(const char* init);
        MyString(const MyString& str);
        ~MyString(void);

        bool IsEmpty(void);
        bool IsEqual(const MyString& str);
        bool operator==(const MyString& str);
        int Length();
        void Resize(int new_size);

        MyString Substr(int start, int num);
        MyString Concat(MyString start);
        MyString Insert(MyString t, int start);

        int Find(MyString pat);

        void Print(void);
    
    private:
        char* str_ = nullptr;   // 마지막에 NUL 없음
        int size_ = 0;
};

MyString::MyString(void)
{
    this->str_ = nullptr;
    this->size_ = 0;
}

MyString::MyString(const char* init)
{
    this->size_ = 0;
    while (init[this->size_] != '\0')
        this->size_ += 1;
    this->size_ -= 1;

    this->str_ = new char[this->size_];
    memcpy(this->str_, init, this->size_);
}

MyString::MyString(const MyString& str)
{
    this->size_ = str.size_;
    this->str_ = new char[this->size_];
    memcpy(this->str_, str.str_, this->size_);
}

MyString::~MyString(void)
{
    if (this->str_ == nullptr)
        return ;
    delete[] this->str_;
}

bool MyString::IsEmpty(void)
{
    return this->str_ == nullptr;
}

bool MyString::IsEqual(const MyString &str)
{
    return (this->size_ == str.size_) 
        && (strncmp(this->str_, str.str_, this->size_) == 0);
}

bool MyString::operator==(const MyString& str)
{
    return this->IsEqual(str);
}

int MyString::Length()
{
    return this->size_;
}

void MyString::Resize(int new_size)
{
    if (new_size == this->size_)
        return ;
    
    char* newptr = new char[new_size];
    memcpy(newptr, this->str_, this->size_ > new_size ? new_size : this->size_);

    delete[] this->str_;
    this->str_ = newptr;
    this->size_ = new_size;
}

MyString MyString::Substr(int start, int num)
{
    char* substr_ = new char[num];
    memcpy(substr_, this->str_ + start, num);

    MyString ret = MyString(substr_);
    delete[] substr_;
    return ret;
}

MyString MyString::Concat(MyString app_str)
{
    char* str_ = new char[this->size_ + app_str.size_];
    memcpy(str_, this->str_, this->size_);
    memcpy(str_ + this->size_, app_str.str_, app_str.size_);

    MyString ret = MyString(str_);
    return ret;
}

MyString MyString::Insert(MyString t, int start)
{
    char *str = new char[this->size_ + t.size_];
    memcpy(str, this->str_, start);
    memcpy(str + start, t.str_, t.size_);
    memcpy(str + start + t.size_, this->str_ + start, this->size_ - start);

    MyString ret = MyString(str);
    return ret;
}


int MyString::Find(MyString pat)
{
    for (int i = 0; i < this->size_ - pat.size_; i++)
    {
        int index = 0;
        while (index < pat.size_ && this->str_[i + index] == pat.str_[index])
            index++;
        if (index == pat.size_)
            return i;
    }
    return -1;
}

void MyString::Print(void)
{
    for (int i = 0; i < this->size_; i++)
        std::cout << this->str_[i];
    std::cout << std::endl;
}
