#include<vector>
#include<string>
#include<iostream>
#include<queue>


template<typename T>
struct VariantTypeNode{
    T content;
    VariantTypeNode* left = NULL;
    VariantTypeNode* right = NULL;
};

struct binaryTree{
    private:
    VariantTypeNode<int>* root;
    int size;
    std::vector<int> leafLevels;
    

    VariantTypeNode<int>* deleteValue_impl(VariantTypeNode<int>* root, int value){
        if (!root)
        {
            return NULL;
        }


        if (value < root->content)
        {
            root->left = deleteValue_impl(root->left, value);
        }
        else if (value > root->content)
        {
            root->right = deleteValue_impl(root->right, value);
        }
        else{
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
            root->right = deleteValue_impl(succNode, root->content);
        }
        
        size--;
        return root;
    }

    // infix search
    VariantTypeNode<int>* find_impl(VariantTypeNode<int>* root, int value){
        if (root == NULL)
        {
            return NULL;
        } else if (root->content == value)
        {
            return root;
        }else{
            VariantTypeNode<int>* it = find_impl(root->left, value);
            if (it != NULL)
            {
                return it;
            }else{
                return find_impl(root->right, value);
            }
        }
        
    }


    public:

    binaryTree(int content){
        root = new VariantTypeNode<int>({content});
        size = 1;
    }


    void deleteValue(int value){
        std::cout << "\n\nTry to delete " << value;
        root = deleteValue_impl(root, value);
    }

    VariantTypeNode<int>* successor(VariantTypeNode<int>* root){
        VariantTypeNode<int>* ptr = root->right;
        while ( ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        return ptr;
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

    void treeInfo(){
        traverseByLevel();
        std::cout << "level of tree : " << lvlOfTree() << std::endl;
        std::cout << "height of tree : level of tree + 1 = " << lvlOfTree() + 1 << std::endl;
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
        return tree.find_impl(tree.getRoot(), value);
    }

    int lvlOfTree(){
        std::queue<VariantTypeNode<int>*> pool;
        VariantTypeNode<int>* current;
        int lvl = -1;

        if (!leafLevels.empty())
        {
            leafLevels.clear();
        }
        

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
                if (!current->left && !current->right)
                {
                    leafLevels.push_back(lvl);
                    continue;
                }
                if (current->left)
                {
                    pool.push(current->left);
                }
                if (current->right)
                {
                    pool.push(current->right);
                }
            }
        }
        return lvl;
    }

    int getTreeSize(){
        return size;
    }

    std::vector<int> getLeafLevels(){
        return leafLevels;
    }

};
