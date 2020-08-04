#include<iostream>
#include<queue>
#include<list>
#include<typeinfo>
#include <string>

template<class T>
void printAll(const T data){
    for(auto item : data){
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}


struct node{
    std::string position;
    node *first, *second;
};


struct org_tree{

    private:
    node* root;

    public:
    static org_tree create_org_structure(const std::string& pos){
        org_tree tree;
        tree.root = new node{pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const std::string& value){
        if(root == NULL)
            return NULL;
        if (root->position == value)
        {
            return root;
        }
        auto firstFound = org_tree::find(root->first, value);
        if (firstFound != NULL)
        {
            return firstFound;
        }else{
            return org_tree::find(root->second, value);
        }
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate){

        auto managerNode = org_tree::find(root, manager);
        if(!managerNode){
            std::cout << "No position named " << manager << std::endl;
            return false;
        }
        else if (managerNode->first && managerNode->second)
        {
            std::cout << manager << " alreeady has 2 subordinate\n";
            return false;
        }
        else{
            if (!managerNode->first)
            {
                managerNode->first = new node{subordinate, NULL, NULL};
            }
            else{
                managerNode->second = new node{subordinate, NULL, NULL};
            }
            std::cout << subordinate << " has been added\n";
            return true;
        }
    }

    static void traverse(const node* sub){
        if (!sub)
        {
            return;
        }else{
            std::cout << sub->position << ", ";
        }
        org_tree::traverse(sub->first);
        org_tree::traverse(sub->second);
    }

    node* getRoot(){
        return root;
    }

    static void levelOrderTraverse(node* start){
        if(!start)
            return;
        std::queue<node*> q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                node* current = q.front();
                q.pop();
                std::cout << current->position << " ";
                if (current->first)
                {
                    q.push(current->first);
                }
                if (current->second)
                {
                    q.push(current->second);
                }
            }
            std::cout << std::endl;
        }
    }

    int level(const std::string& target){
        int level = -1;
        if (!root)
        {
            return level;
        }else{
            std::queue<node*> pool;
            pool.push(root);
            bool find=false;
            while( !pool.empty() ){
                level++;
                int size=pool.size();
                for(int i=0; i<size; i++){
                    node* current = pool.front();
                    pool.pop();
                    if (current->position.compare(target) == 0)
                    {
                        return level;
                    }
                    
                    if (current->first)
                    {
                        pool.push(current->first);
                    }
                    if (current->second)
                    {
                        pool.push(current->second);
                    }
                }
            }
            return -1;
        }
    }

    static void example(){

    org_tree data = org_tree::create_org_structure("CEO");
    data.addSubordinate("CEO", "Deputy Director");
    data.addSubordinate("Deputy Director", "IT Division");
    data.addSubordinate("IT Division", "Security Head");
    data.addSubordinate("IT Division", "App Development Head");
    data.addSubordinate("Deputy Director", "Marketing Head");
    data.addSubordinate("Marketing Head", "Logistic Head");

    // org_tree::traverse(data.getRoot());
    org_tree::levelOrderTraverse(data.getRoot());
    std::cout << data.level("Marketing Head");

    }
};

template<typename T>
struct VariantTypeNode{
    T content;
    VariantTypeNode* left = NULL;
    VariantTypeNode* right = NULL;
};

template<typename dataType>
struct GenericTree{
    private:
    VariantTypeNode<dataType>* root;

    GenericTree(dataType content){
        root = VariantTypeNode<dataType>(content);
    }
};

struct binaryTree{
    private:
    VariantTypeNode<int>* root;
    int size;
    

    VariantTypeNode<int>* deleteValue(VariantTypeNode<int>* root, int value){
        if (!root)
        {
            return NULL;
        }
        if (value < root->content)
        {
            root->left = deleteValue(root->left, value);
        }
        else if (value > root->content)
        {
            root->right = deleteValue(root->right, value);
        }
        else{
            size--;
            if (!root->left)
            {
                auto tmp = root->right;
                delete root;
                return tmp;
            }
            if (!root->right)
            {
                auto tmp = root->left;
                delete root;
                return tmp;
            }

            auto succNode = successor(root);
            root->content = succNode->content;
            root->right = deleteValue(succNode, root->content);
        }
        
        return root;
    }

    // infix search
    VariantTypeNode<int>* find(VariantTypeNode<int>* root, int value){
        if (root == NULL)
        {
            return NULL;
        } else if (root->content == value)
        {
            return root;
        }else{
            VariantTypeNode<int>* it = find(root->left, value);
            if (it != NULL)
            {
                return it;
            }else{
                return find(root->right, value);
            }
        }
        
    }

    public:

    void deleteValue(int value){
        std::cout << "\n\nTry to delete " << value;
        root = deleteValue(root, value);
    }

    binaryTree(int content){
        root = new VariantTypeNode<int>({content});
        size = 1;
    }

    VariantTypeNode<int>* getRoot(){
        return root;
    }

    void insert(int value){
        size++;
        VariantTypeNode<int>* current = root;
        while(1){
            if(current->content < value){
                if (!current->right)
                {
                    current->right = new VariantTypeNode<int>({value});
                    return;
                }else{
                    current = current->right;
                }
            }
            else{
                if (!current->left)
                {
                    current->left = new VariantTypeNode<int>({value});
                    return;
                }else{
                    current = current->left;
                }
            }
        }
    }

    void insert(std::vector<int> value_list){
        for(auto it:value_list){
            this->insert(it);
        }
    }

    void traverseByLevel(){
        std::queue<VariantTypeNode<int>*> pool;
        VariantTypeNode<int>* current;
        std::cout << "\ntraverse\n";
        pool.push(root);
        while (!pool.empty())
        {
            int size=pool.size();
            for(int i=0; i<size; i++){
                current = pool.front();
                std::cout << current->content << " ";
                pool.pop();
                if (current->left)
                {
                    pool.push(current->left);
                }
                if (current->right)
                {
                    pool.push(current->right);
                }
            }
            std::cout << std::endl;
        }
        
    }

    static bool find(binaryTree tree, int value){
        return tree.find(tree.getRoot(), value);
    }

    int lvlOfTree(){
        std::queue<VariantTypeNode<int>*> pool;
        VariantTypeNode<int>* current;
        int lvl = -1;

        if (root == NULL)
        {
            return lvl;
        }
    
        pool.push(root);
        while (!pool.empty())
        {
            lvl++;
            int size = pool.size();
            for(int i=0; i<size; i++){
                current = pool.front();
                pool.pop();
                if (current->left != NULL)
                {
                    pool.push(current->left);
                }
                if (current->right != NULL)
                {
                    pool.push(current->right);
                }
            }
        }
        return lvl;
    }

    VariantTypeNode<int>* successor(VariantTypeNode<int>* root){
        VariantTypeNode<int>* ptr = root->right;
        while ( ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        return ptr;
    }

    int getTreeSize(){
        return size;
    }
};

int main(int argc, char* argv[]){

    binaryTree tree(3);

    tree.insert(std::vector<int>{1,2,3,4,5,13,55,21});
    tree.traverseByLevel();
    std::cout << "level of a tree : " << tree.lvlOfTree() << std::endl;
    std::cout << "tree size : " << tree.getTreeSize();
    tree.deleteValue(13);
    tree.traverseByLevel();
    std::cout << "tree size : " << tree.getTreeSize();


    return 0;
}