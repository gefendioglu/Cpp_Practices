#include <iostream>
#include <string>

class ResourceHandle {};
class Resource {
public:
	Resource() { handle = openResource(); }
	~Resource() { closeResource(handle); }
	ResourceHandle getHandle() { return handle; }
private:
	ResourceHandle handle;
	Resource(Resource const&); // private copy constructor
	Resource& operator= (Resource const&); // private assignment operator
};

void useResource() {
	Resource r; 
	/* Use resource here */
}

int main()
{

}




