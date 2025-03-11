class Singleton
{

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    };

private:
    Singleton() {};

    Singleton(Singleton const &) = delete;

    void operator=(Singleton const &) = delete;
};