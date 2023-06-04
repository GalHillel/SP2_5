#include "MagicalContainer.hpp"

namespace ariel
{

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
        : container(container), forward(container.elements.begin()), backward(container.elements.end() - 1), isForward(true) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), forward(other.forward), backward(other.backward), isForward(other.isForward) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this != &other)
        {
            if (&container != &other.container)
            {
                throw std::runtime_error("Cannot assign iterators from different containers");
            }
            forward = other.forward;
            backward = other.backward;
            isForward = other.isForward;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return forward == other.forward && backward == other.backward && isForward == other.isForward;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return forward > other.forward;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return forward < other.forward;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if (isForward)
        {
            if (forward == container.elements.end())
            {
                throw std::runtime_error("Iterator out of range");
            }
            return *forward;
        }
        else
        {
            if (backward == container.elements.begin() - 1)
            {
                throw std::runtime_error("Iterator out of range");
            }
            return *backward;
        }
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (isForward)
        {
            if (forward == container.elements.end())
            {
                throw std::runtime_error("Iterator out of range");
            }
            ++forward;
        }
        else
        {
            if (backward == container.elements.begin() - 1)
            {
                throw std::runtime_error("Iterator out of range");
            }
            --backward;
        }

        isForward = !isForward;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        return SideCrossIterator(container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
    {
        SideCrossIterator iter(container);
        iter.forward = container.elements.end();
        iter.backward = container.elements.begin() - 1;
        return iter;
    }

}
