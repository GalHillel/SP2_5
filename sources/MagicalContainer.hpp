#include <vector>
#include <iterator>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        MagicalContainer();
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        int size();

        class AscendingIterator
        {
        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator current;

        public:
            AscendingIterator(const MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator &operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator forward;
            std::vector<int>::const_iterator backward;
            bool isForward;

        public:
            SideCrossIterator(const MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator current;

        public:
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();
            PrimeIterator &operator=(const PrimeIterator &other);
            bool isPrime(int number);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator &operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}