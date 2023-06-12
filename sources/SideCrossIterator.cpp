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
        return forward == other.forward && backward == other.backward && isForward == other.isForward &&
               &container == &other.container; // Compare the container's addresses to ensure iterators are from the same container
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
        if (isForward && forward != container.elements.end())
        {
            ++forward;
        }
        else if (backward != container.elements.begin() - 1)
        {
            --backward;
        }
        else if (backward == container.elements.begin() - 1 || forward == container.elements.end())
        {
            throw std::runtime_error("Iterator out of range");
        }

        isForward = !isForward;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        SideCrossIterator iter(container);
        iter.isForward = true;
        iter.forward = container.elements.begin();    // Set the forward iterator to the beginning
        iter.backward = container.elements.end() - 1; // Set the backward iterator to the last element
        return iter;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() 
    {
        SideCrossIterator iter(container);
        iter.isForward = true;
        iter.forward = container.elements.end();        // Set the forward iterator to one position after the last element
        iter.backward = container.elements.begin() - 1; // Set the backward iterator to one position before the first element
        return iter;
    }
}