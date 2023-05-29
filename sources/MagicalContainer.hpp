
namespace ariel
{
    class MagicalContainer
    {
    private:
        /* data */
    public:
        MagicalContainer();
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        int size();
    };

    MagicalContainer::MagicalContainer()
    {
    }

    MagicalContainer::~MagicalContainer()
    {
    }

}