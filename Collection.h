// Collection.h: interface for the Collection class.
//
//////////////////////////////////////////////////////////////////////

#ifndef COLLECTION_H
#define COLLECTION_H

#define ALLOC_BLOCK_SIZE 4

template <class type>
class Collection  
{
private:
	int size;
	int allocsize;
	type* collection;

private:
	bool Resize()
	{
		if ((this->size % ALLOC_BLOCK_SIZE) == 0)
		{
			type* tmp = new type[this->size + ALLOC_BLOCK_SIZE];
			memset(tmp, 0, sizeof(type) * (this->size + ALLOC_BLOCK_SIZE));

			if (tmp)
			{
				for (int i = 0; i < this->size; i++)
				{
					if (this->collection[i] != 0)
						tmp[i] = this->collection[i];
				}

				delete [] this->collection;
				this->collection = tmp;

				return true;
			}
			return false;
		}
		return true;
	}

public:
	Collection()
	{
		this->size = 0;
		this->allocsize = 0;
		this->collection = 0;
	}

	~Collection()
	{
		Clear();
	}

	int Add(type ptr)
	{
		if (Resize())
		{
			this->collection[this->size] = ptr;
			return this->size++;
		}

		return -1;
	}

	type Get(int index)
	{
		if (index < this->size && index >= 0)
		{
			return this->collection[index];
		}
		return 0;
	}

	type operator[](int index)
	{
		if (index < this->size && index >= 0)
		{
			return this->collection[index];
		}
		return 0;
	}

	bool Remove(int index)
	{
		if (index < this->size && index >= 0)
		{
			delete this->collection[index];
			this->collection[index] = 0;
			Resize();
			this->size--;
			return true;
		}
		return false;
	}

	int Size()
	{
		return this->size;
	}

	void Clear()
	{
		if (this->collection)
		{
			delete [] this->collection;
			this->collection = 0;
			this->size = 0;
		}
	}

};

#endif
