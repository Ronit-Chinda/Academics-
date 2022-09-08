#include <stdio.h>
#include <stdlib.h>

struct Photo
{
    int identifier;

    int ratings[10];
    int ratingsSize;
    int oldestRating;
    float avgRating;

    int ratingMaxHeap[6];
    int ratingMaxHeapSize;

    int ratingMinHeap[6];
    int ratingMinHeapSize;
};

void photoSwap(struct Photo photos[], int first, int second)
{
    struct Photo temp = photos[first];
    photos[first] = photos[second];
    photos[second] = temp;
}
void intSwap(int array[], int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}
float getAverage(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum / size;
}
int checkValidRating(int rating, int median)
{
    if ((rating >= 0 && rating <= 20) && (median - 3 <= rating && rating <= median + 3))
    {
        return 1;
    }
    return 0;
}

int getIdentifierIndex(struct Photo photos[], int size, int identifier)
{
    for (int i = 0; i < size; i++)
    {
        if (photos[i].identifier == identifier)
        {
            return i;
        }
    }
    return -1;
}
int getMinimumIdentifier(struct Photo photos[], int size)
{
    int min = photos[0].identifier;
    int minIdx = -1;
    for (int i = 0; i < size; i++)
    {
        if (photos[i].identifier <= min)
        {
            min = photos[i].identifier;
            minIdx = i;
        }
    }
    return minIdx;
}
int getMaximumIdentifier(struct Photo photos[], int size)
{
    int max = photos[0].identifier;
    int maxIdx = -1;
    for (int i = 0; i < size; i++)
    {
        if (photos[i].identifier >= max)
        {
            max = photos[i].identifier;
            maxIdx = i;
        }
    }
    return maxIdx;
}

struct Photo newPhoto(struct Photo photos[], int size)
{
    struct Photo temp;
    int max_idx = getMaximumIdentifier(photos, size);
    if (max_idx == -1)
    {
        temp.identifier = 1;
    }
    else
    {
        temp.identifier = photos[max_idx].identifier + 1;
    }
    temp.ratingsSize = 0;
    temp.avgRating = 0;
    temp.ratingMinHeapSize = 0;
    temp.ratingMaxHeapSize = 0;
    return temp;
}

void photoMaxHeapifyUp(struct Photo photos[], int size, int index)
{
    if (index)
    {
        int parent;
        if (index % 2 == 0)
        {
            parent = (index - 2) / 2;
        }
        else
        {
            parent = (index - 1) / 2;
        }
        if (photos[parent].avgRating < photos[index].avgRating)
        {
            photoSwap(photos, index, parent);
            photoMaxHeapifyUp(photos, size, parent);
        }
    }
}
void photoMaxHeapifyDown(struct Photo photos[], int size, int index)
{
    int maximum = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && photos[left].avgRating > photos[maximum].avgRating)
    {
        maximum = left;
    }
    if (right < size && photos[right].avgRating > photos[maximum].avgRating)
    {
        maximum = right;
    }
    if (maximum != index)
    {
        photoSwap(photos, maximum, index);
        photoMaxHeapifyDown(photos, size, maximum);
    }
}
void buildPhotoMaxHeap(struct Photo photos[], int size)
{
    int init = (size / 2) - 1;

    for (int i = init; i >= 0; i--)
    {
        photoMaxHeapifyDown(photos, size, i);
    }
}

void ratingMinHeapifyUp(int array[], int size, int index)
{
    if (index)
    {
        int parent;
        if (index % 2 == 0)
        {
            parent = (index - 2) / 2;
        }
        else
        {
            parent = (index - 1) / 2;
        }
        if (array[parent] > array[index])
        {
            intSwap(array, index, parent);
            ratingMinHeapifyUp(array, size, parent);
        }
    }
}
void ratingMinHeapifyDown(int array[], int size, int index)
{

    int minimum = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && array[left] < array[minimum])
    {
        minimum = left;
    }
    if (right < size && array[right] < array[minimum])
    {
        minimum = right;
    }
    if (minimum != index)
    {
        intSwap(array, minimum, index);
        ratingMinHeapifyDown(array, size, index);
    }
}
void insertMinHeap(int min_heap[], int *ratingMinHeapSize, int key)
{
    min_heap[(*ratingMinHeapSize)++] = key;
    ratingMinHeapifyUp(min_heap, *ratingMinHeapSize, (*ratingMinHeapSize) - 1);
}
int getMinimum(int min_heap[])
{
    return min_heap[0];
}
int extract_min(int min_heap[], int *ratingMinHeapSize)
{
    if (*ratingMinHeapSize == 0)
    {
        return -1;
    }
    if (*ratingMinHeapSize == 1)
    {
        return min_heap[0];
    }
    int min = min_heap[0];
    min_heap[0] = min_heap[(*ratingMinHeapSize) - 1];
    ratingMinHeapifyUp(min_heap, (*ratingMinHeapSize) - 1, 0);
    return min;
}

void ratingMaxHeapifyUp(int array[], int size, int index)
{
    if (index)
    {
        int parent;
        if (index % 2 == 0)
        {
            parent = (index - 2) / 2;
        }
        else
        {
            parent = (index - 1) / 2;
        }
        if (array[parent] < array[index])
        {
            intSwap(array, index, parent);
            ratingMaxHeapifyUp(array, size, parent);
        }
    }
}
void ratingMaxHeapifyDown(int array[], int size, int index)
{
    int maximum = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && array[left] > array[maximum])
    {
        maximum = left;
    }
    if (right < size && array[right] > array[maximum])
    {
        maximum = right;
    }
    if (maximum != index)
    {
        intSwap(array, maximum, index);
        ratingMaxHeapifyDown(array, size, index);
    }
}
void insertMaxHeap(int max_heap[], int *ratingMaxHeapSize, int key)
{
    max_heap[(*ratingMaxHeapSize)++] = key;
    ratingMaxHeapifyUp(max_heap, *ratingMaxHeapSize, (*ratingMaxHeapSize) - 1);
}
int getMaximum(int max_heap[])
{
    return max_heap[0];
}
int extract_max(int max_heap[], int *ratingMaxHeapSize)
{

    if (*ratingMaxHeapSize == 0)
    {
        return -1;
    }
    if (*ratingMaxHeapSize == 1)
    {
        return max_heap[0];
    }
    int max = max_heap[0];
    max_heap[0] = max_heap[(*ratingMaxHeapSize) - 1];
    ratingMaxHeapifyDown(max_heap, (*ratingMaxHeapSize) - 1, 0);
    return max;
}

int getMedian(int min_heap[], int ratingMinHeapSize, int max_heap[], int ratingMaxHeapSize)
{
    if (ratingMaxHeapSize == ratingMinHeapSize)
    {
        return (getMinimum(min_heap) + getMaximum(max_heap)) / 2;
    }
    else if (ratingMaxHeapSize > ratingMinHeapSize)
    {
        return getMaximum(max_heap);
    }
    else if (ratingMaxHeapSize < ratingMinHeapSize)
    {
        return getMinimum(min_heap);
    }
}
void displayPhoto(struct Photo Photo)
{
    int median = getMedian(Photo.ratingMinHeap, Photo.ratingMinHeapSize, Photo.ratingMaxHeap, Photo.ratingMaxHeapSize);
    printf("\tIdentifier: %d Average rating: %d Median rating: %d Ratings: [ ", Photo.identifier, (int)Photo.avgRating, median);
    for (int _ = 0; _ < Photo.ratingsSize; _++)
    {
        printf("%d ", Photo.ratings[_]);
    }
    printf("]\n");
}

void updateMedian(int min_heap[], int *ratingMinHeapSize, int max_heap[], int *ratingMaxHeapSize, int median, int rate)
{
    if (*ratingMaxHeapSize > *ratingMinHeapSize)
    {
        if (rate < median)
        {
            insertMinHeap(min_heap, ratingMinHeapSize, extract_max(max_heap, ratingMaxHeapSize));
            insertMaxHeap(max_heap, ratingMaxHeapSize, rate);
        }
        else
        {
            insertMinHeap(min_heap, ratingMinHeapSize, rate);
        }
    }
    else if (*ratingMinHeapSize > *ratingMaxHeapSize)
    {
        if (rate < median)
        {
            insertMaxHeap(max_heap, ratingMaxHeapSize, rate);
        }
        else
        {
            insertMaxHeap(max_heap, ratingMaxHeapSize, extract_min(min_heap, ratingMinHeapSize));
            insertMinHeap(min_heap, ratingMinHeapSize, rate);
        }
    }
    else
    {
        if (rate < median)
        {
            insertMaxHeap(max_heap, ratingMaxHeapSize, rate);
        }
        else
        {
            insertMinHeap(min_heap, ratingMinHeapSize, rate);
        }
    }
}
void updateRating(struct Photo photos[], int size, int index)
{
    if (index == -1)
    {
        printf("Identifier not found \n");
    }
    else
    {
        int rating;
        printf("Enter rating:\n");
        scanf("%d", &rating);
        int median = getMedian(photos[index].ratingMinHeap, photos[index].ratingMinHeapSize, photos[index].ratingMaxHeap, photos[index].ratingMaxHeapSize);
        if (checkValidRating(rating, median) || photos[index].ratingsSize == 0)
        {
            if (photos[index].ratingsSize < 10)
            {
                photos[index].ratings[photos[index].ratingsSize++] = rating;
            }
            else
            {
                photos[index].ratings[photos[index].oldestRating] = rating;
                photos[index].oldestRating = (photos[index].oldestRating + 1) % photos[index].ratingsSize;
            }
            photos[index].avgRating = getAverage(photos[index].ratings, photos[index].ratingsSize);
            updateMedian(photos[index].ratingMinHeap, &(photos[index].ratingMinHeapSize), photos[index].ratingMaxHeap, &(photos[index].ratingMaxHeapSize), median, rating);
        }
        else
        {
            printf("Invalid rating\n");
        }
    }
}

void insertPhoto(struct Photo photos[], int *size)
{
    if (*size == 1)
    {
        photos[*size] = newPhoto(photos, *size);
        printf("Jury:\n");
        updateRating(photos, *size, *size);
        updateRating(photos, *size, *size);
        updateRating(photos, *size, *size);
        (*size)++;
        buildPhotoMaxHeap(photos, *size);
    }
    else if (*size < 10)
    {
        photos[*size] = newPhoto(photos, *size);
        printf("Jury:\n");
        updateRating(photos, *size, *size);
        updateRating(photos, *size, *size);
        updateRating(photos, *size, *size);
        (*size)++;
        photoMaxHeapifyUp(photos, *size, (*size) - 1);
    }
    else
    {
        int old = getMinimumIdentifier(photos, *size);
        photos[old] = newPhoto(photos, *size);
        printf("Jury:\n");
        updateRating(photos, *size, old);
        updateRating(photos, *size, old);
        updateRating(photos, *size, old);
        photoMaxHeapifyUp(photos, *size, old);
    }
}
void removePhoto(struct Photo photos[], int *size)
{
    if (*size == 0)
    {
        printf("No photos\n");
    }
    else
    {
        int identifier;
        printf("Enter identifier of Photo to be deleted (-1 to go back)\n");
        scanf("%d", &identifier);
        if (identifier != -1)
        {
            int index = getIdentifierIndex(photos, *size, identifier);
            if (index == -1)
            {
                printf("Identifier not found\n");
            }
            else
            {
                printf("Photo being deleted : \n");
                displayPhoto(photos[index]);
                if (index != (*size) - 1)
                {
                    photoSwap(photos, index, (*size) - 1);
                }
                (*size)--;
                photoMaxHeapifyDown(photos, *size, 0);
            }
        }
    }
}

void displayAllPhotos(struct Photo photos[], int size)
{
    printf("Current Size : %d \n", size);
    for (int i = 0; i < size; i++)
    {
        displayPhoto(photos[i]);
    }
}

int main()
{
    struct Photo photos[10];
    int photosSize = 0;
    while (1)
    {
        printf("0 - Exit\n");
        printf("1 - Add Photo\n");
        printf("2 - Update Rating\n");
        printf("3 - Remove Photo\n");
        printf("4 - Print All Photos\n");
        printf("5 - Print Highest Rated Photo\n");

        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            insertPhoto(photos, &photosSize);
        }
        else if (choice == 2)
        {
            int identifier;
            printf("Enter identifier of Photo to rate\n");
            scanf("%d", &identifier);
            updateRating(photos, photosSize, getIdentifierIndex(photos, photosSize, identifier));
        }
        else if (choice == 3)
        {
            removePhoto(photos, &photosSize);
        }
        else if (choice == 4)
        {
            displayAllPhotos(photos, photosSize);
        }
        else if (choice == 5)
        {
            if (photosSize != 0)
            {
                displayPhoto(photos[0]);
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
}
