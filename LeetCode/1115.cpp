class FooBar {
private:
    int n;
    mutex m1;
    mutex m2;

public:
    FooBar(int n) {
        this->n = n;
        m1.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            m2.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m1.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            m1.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m2.unlock();
        }
    }
};
