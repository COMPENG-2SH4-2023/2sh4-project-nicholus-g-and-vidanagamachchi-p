#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeArray = ARRAY_MAX_CAP; // Use the defined macro for capacity
    sizeList = 0; // Initially empty
    aList = new objPos[sizeArray]; // Allocate memory for the array using the sizeArray
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Shift all elements to the right
        for (int i = sizeList; i > 0; --i) 
        {
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos; // Insert new head
        ++sizeList;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[sizeList] = thisPos; // Add new element at the end
        ++sizeList;
}

void objPosArrayList::removeHead()
{
    if (sizeList > 0) 
    {
        // Shift all elements to the left
        for (int i = 0; i < sizeList - 1; ++i) 
        {
            aList[i] = aList[i + 1];
        }
        --sizeList; // Decrease the size of the list
    }
}

void objPosArrayList::removeTail()
{
    if (sizeList > 0) 
    {
        --sizeList; // Simply decrease the size of the list
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    if (sizeList > 0) 
    {
        returnPos = aList[0]; // Return the head element
    }
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    if (sizeList > 0) 
    {
        returnPos = aList[sizeList - 1]; // Return the tail element
    }
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index >= 0 && index < sizeList) 
    {
        returnPos = aList[index]; // Return the element at the given index
    }
}