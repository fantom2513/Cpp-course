#include"IntArray.h"
#include <cassert>

Bad_lenght::Bad_lenght(const std::string& msg) : _msg(msg) {}

const char* Bad_lenght::what() const noexcept {
    return _msg.c_str();
}

Bad_range::Bad_range(const std::string& msg) : _msg(msg) {}

const char* Bad_range::what() const noexcept {
    return _msg.c_str();
}

IntArray::IntArray(int length) :_mlength(length)
{
    /*assert(length >= 0&& "Lenght<0");*/
    if (length <= 0)
    {
        throw Bad_lenght("Error!Array size<=0.");
    }

    if (length > 0)
        _mdata = new int[length] {};
}
IntArray::~IntArray()
{
    delete[] _mdata;
}

void IntArray::erase()
{
    delete[] _mdata;

    // We need to make sure we set m_data to nullptr here, otherwise it will
    // be left pointing at deallocated memory!
    _mdata = nullptr;
    _mlength = 0;
}


int& IntArray::operator[](int index)
{
    /*assert(index >= 0 && index < _mlength);*/
    if (index >= 0 && index >= _mlength)
    {
        throw Bad_range("Error!Index out of range.");
    }
    return _mdata[index];
}

void IntArray::reallocate(int newLength)
{
    // First we delete any existing elements
    erase();

    // If our array is going to be empty now, return here
    if (newLength <= 0)
        return;

    // Then we have to allocate new elements
    _mdata = new int[newLength];
    _mlength = newLength;
}
// resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
void IntArray::resize(int newLength)
{
    // if the array is already the right length, we're done
    if (newLength == _mlength)
        return;

    // If we are resizing to an empty array, do that and return
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // Now we can assume newLength is at least 1 element.  This algorithm
    // works as follows: First we are going to allocate a new array.  Then we
    // are going to copy elements from the existing array to the new array.
    // Once that is done, we can destroy the old array, and make m_data
    // point to the new array.

    // First we have to allocate a new array
    int* data = new int[newLength];

    // Then we have to figure out how many elements to copy from the existing
    // array to the new array.  We want to copy as many elements as there are
    // in the smaller of the two arrays.
    if (_mlength > 0)
    {
        int elementsToCopy = (newLength > _mlength) ? _mlength : newLength;

        // Now copy the elements one by one
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = _mdata[index];
    }

    // Now we can delete the old array because we don't need it any more
    delete[] _mdata;

    // And use the new array instead!  Note that this simply makes m_data point
    // to the same address as the new array we dynamically allocated.  Because
    // data was dynamically allocated, it won't be destroyed when it goes out of scope.
    _mdata = data;
    _mlength = newLength;
}

IntArray::IntArray(const IntArray& a)
{
    // Set the size of the new array appropriately
    reallocate(a.getLength());

    // Then copy the elements
    for (int index{ 0 }; index < _mlength; ++index)
        _mdata[index] = a._mdata[index];
}

IntArray& IntArray::operator=(const IntArray& other)
{
    // Self-assignment check
    if (&other == this)
        return *this;

    // Set the size of the new array appropriately
    IntArray::reallocate(other.getLength());

    // Then copy the elements
    for (int index{ 0 }; index < _mlength; ++index)
        _mdata[index] = other._mdata[index];

    return *this;
}
void IntArray::insertBefore(int value, int index)
{
    // Sanity check our index value
    assert(index >= 0 && index <= _mlength);

    // First create a new array one element larger than the old array
    int* data{ new int[_mlength + 1] };

    // Copy all of the elements up to the index
    for (int before{ 0 }; before < index; ++before)
        data[before] = _mdata[before];

    // Insert our new element into the new array
    data[index] = value;

    // Copy all of the values after the inserted element
    for (int after{ index }; after < _mlength; ++after)
        data[after + 1] = _mdata[after];

    // Finally, delete the old array, and use the new array instead
    delete[] _mdata;
    _mdata = data;
    ++_mlength;
}

void IntArray::remove(int index)
{
    // Sanity check our index value
    assert(index >= 0 && index < _mlength);

    // If this is the last remaining element in the array, set the array to empty and bail out
    if (_mlength == 1)
    {
        erase();
        return;
    }

    // First create a new array one element smaller than the old array
    int* data{ new int[_mlength - 1] };

    // Copy all of the elements up to the index
    for (int before{ 0 }; before < index; ++before)
        data[before] = _mdata[before];

    // Copy all of the values after the removed element
    for (int after{ index + 1 }; after < _mlength; ++after)
        data[after - 1] = _mdata[after];

    // Finally, delete the old array, and use the new array instead
    delete[] _mdata;
    _mdata = data;
    --_mlength;
}
