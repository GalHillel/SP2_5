#include "MagicalContainer.hpp"
#include <cmath>

namespace ariel
{
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
        : container(container), current(container.elements.begin())
    {
        // Initialize the iterator to the first prime element in the container
        while (current != container.elements.end() && !isPrime(*current))
        {
            ++current;
        }
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), current(other.current) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this != &other)
        {
            if (&container != &other.container)
            {
                throw std::runtime_error("Cannot assign iterators from different containers");
            }
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number)
    {
        if (number <= 1)
        {
            return false;
        }

        for (int i = 2; i * i <= number; ++i)
        {
            if (number % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return current == other.current;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return current > other.current;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return current < other.current;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return *current;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (current == container.elements.end())
        {
            throw std::runtime_error("Iterator out of range");
        }

        ++current;
        while (current != container.elements.end() && !isPrime(*current))
        {
            ++current;
        }

        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        PrimeIterator iter(*this);
        iter.current = container.elements.begin();
        while (iter.current != container.elements.end() && !isPrime(*iter.current))
        {
            ++iter.current;
        }
        return iter;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator iter(*this);
        iter.current = container.elements.end();
        return iter;
    }
}