/**
 * a reference counting class
 */
class Counter
{
    private:
        int count;

    public:
        int inc()
        {
            return ++count;
        }

        int dec()
        {
            return --count;
        }
};
