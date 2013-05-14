/**
 * a reference counting class
 */
class Counter
{
    private:
        int counter;

    public:
        int AddRef()
        {
            return ++count;
        }

        int Release()
        {
            return --count;
        }
}
