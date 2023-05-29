#include "MagicalContainer.hpp"
#include <cmath>

namespace ariel
{
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
        : container(container), current(container.elements.begin()) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), current(other.current) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this != &other)
        {
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
        ++current;
        while (current != container.elements.end())
        {
            bool isPrime = true;
            int num = *current;
            for (int i = 2; i <= std::sqrt(num); ++i)
            {
                if (num % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                break;
            }
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