class Foo {
public:
    Foo() {
        count = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while (count != 2) {
            cv.wait(lck);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while (count != 3) {
            cv.wait(lck);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    int count;
    mutex mtx;
    condition_variable cv;
};
