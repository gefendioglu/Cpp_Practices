## Resource Management 

- In C++, whenever you exit a function, whether by a return statement or because of an exception, all of the automatic (local) objects that pass out of scope are destroyed. How might you use this to ensure that you avoid leaking resources?

- You can create a class to wrap the resource. If you call openResource in the constructor and closeResource in the destructor, you can use the life cycle of the object to manage the resource. All you have to do is remember to declare the object as a local object on the stack so that it will be automatically destroyed (static objects?).

- A violation of this case: If an instance of the wrapper class were copied, then both objects would wrap the same resource handle, and each object would try to release the handle when the object was destroyed. One way to guard against this is to declare private copy constructor and assignment operators to prevent the object from being duplicated.

- The C++ approach represents all of the necessary logic in one place in the wrapper class, so there’s no duplication and the code that uses the resource is simple and clean.

- The pattern embodied by this C++ approach is commonly called Resource Acquisition Is Initialization (RAII), and is the preferred way to manage resources in C++. RAII relies on deterministic, immediate destruction of automatic objects when they go out of scope, which ensures that resources are released as soon as they’re no longer accessible through their wrapper objects.

- C# and Java provides try/finally functionality for resource management, but lacks the ability to do true RAII because it does not have deterministic destruction of automatic objects. (Java 1.7 added try-with-resources that is more limited than RAII in C++)

/----------------------------------------------
/----------------------------------------------

- **Example** : Resource Management (Pseudo Code)
  - Suppose you have a function that needs to access a limited system resource. 
  - The code must call an API function openResource to obtain a handle to the resource, and must pass this handle to a function closeResource when it’s done. 
  - How can you ensure that closeResource will be called in all cases and the resource will never be leaked?

```cpp
class Resource {
public:
	Resource() { handle = openResource(); } // memory is allocated in constructor 
	~Resource() { closeResource(handle); }  // memory is deallocated in ddestructor by destroying object 
	ResourceHandle getHandle() { return handle; }
private:
	ResourceHandle handle;
	Resource(Resource const&);             // private copy constructor as a guard (why isnt it deleted?) 
	Resource& operator= (Resource const&); // private assignment operator as a guard (why isnt it deleted?)
};

void useResource() {
	Resource r; 
	/* Use resource here */
}
```

/----------------------------------------------
/----------------------------------------------
