#include <malloc.h>

#define DEFAULT_MEMORY_POOL_SIZE 1024*1024
#define GETBSIZE(start) *( (int*)start )
#defome GETSTATUS(start) *( (int *)start + 1)

class MemoryManager
{
public:
	MemoryManager();
	~MemoryManager();

public:
	void *my_malloc(int size);
	void my_free();
private:
	int my_align(int size);
private:
	void *start;
	int size;
};

MemoryManager::MemoryManager()
{
	start = malloc(DEFAULT_MEMORY_POOL_SIZE);
	if (start == NULL) {
		exit(0);
	}
	size = DEFAULT_MEMORY_POOL_SIZE;
}

MemoryManager::~MemoryManager()
{
	free(start);
	size = 0;
}

void MemoryManager::my_malloc(size)
{
	
}