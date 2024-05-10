

queue<int> qIntegers; //declaring here as if declared inside it will be intialized in every run in recurion
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto& niIt : nestedList) {
            if (niIt.isInteger()) 
                qIntegers.push(niIt.getInteger());
            else
                NestedIterator(niIt.getList());
        }
    }
    
    int next() {
        int nextInt = qIntegers.front();
        qIntegers.pop();
        return nextInt;
    }
    
    bool hasNext() {
        return !qIntegers.empty();
    }
};
