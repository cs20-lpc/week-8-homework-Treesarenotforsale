template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (!isEmpty()) {
        pop();
    }
    top = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    if (copyObj.isEmpty()) {
        top = nullptr;
        this->length = 0;
        return;
    }
    // Copy the first node
    top = new Node<T>(copyObj.top->data);
    Node<T>* current = top;
    Node<T>* copyCurrent = copyObj.top->next;

    while (copyCurrent != nullptr) {
        current->next = new Node<T>(copyCurrent->data);
        current = current->next;
        copyCurrent = copyCurrent->next;
    }
    this->length = copyObj.length;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty. Cannot peek.");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty. Cannot pop.");
    }
    Node<T>* temp = top;
    top = top->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty() || this->length == 1) {
        return; // No need to rotate if stack is empty or has one element
    }
    if (dir == Stack<T>::LEFT) {
        // Rotate left
        Node<T>* first = top;
        Node<T>* current = top;

        while (current->next != nullptr) {
            current = current->next;
        }
        top = first->next;
        current->next = first;
        first->next = nullptr;
    } else {
        // Rotate right
        Node<T>* prev = nullptr;
        Node<T>* current = top;

        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        if (prev != nullptr) {
            prev->next = nullptr;
            current->next = top;
            top = current;
        }
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
