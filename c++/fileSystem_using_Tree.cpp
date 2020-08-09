#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>


enum FileType{
    directory, file
};

struct nTree
{
    int data;
    std::vector<nTree*> children;
};

struct nTree_File{ 
    FileType type;
    std::string name;

    std::vector<nTree_File *> children;
};


struct FileSystem{
    private:
        nTree_File root;
        nTree_File* current;

        nTree_File* find(nTree_File* start, std::string path){
            if (!start)
            {
                return NULL;
            }
            if (start->name == path || start->name == path.substr(0, path.size()-1))
            {
                return start;
            }
            
            for(auto item : start->children){
                if (item->name == path.substr(0, path.find("/")))
                {
                    return find(item, path.substr(path.find("/") + 1));
                }
                
            }
            return NULL;
        }

    public:
        FileSystem(){
            root = nTree_File{directory, "/"};
            current = &root;
        }

        nTree_File* find(std::string path){
            if (*path.begin() == '/')
            {
                return find(&root, path.substr(1));
            }else if(path.substr(0, 2) == "./"){
                return path == "./" ? current : find(path.substr(2));
            }
            else
            {
                return find(current, path);
            }
        }

        void add(std::string path, FileType type, std::string filename){
            nTree_File* target = find(path);
            if (!target)
            {
                std::cout << "\nSuch file doesn't exist\n";
                return;
            }
            if (target->type != FileType(directory))
            {
                std::cout << "\nIt's not directory\n";
                return;
            }
            target->children.push_back(new nTree_File{FileType(type), filename});
            std::cout << std::endl << filename << " has been inserted\n";
        }

        void list(std::string path){
            nTree_File* target = find(path);
            if (!target)
            {
                std::cout << "\nSuch file doesn't exist\n";
                return;
            }
            if (target->type != FileType(directory))
            {
                std::cout << "\nIt's not directory\n";
                return;
            }
            std::cout << std::endl << "below " << path << " : \n";
            for(auto item : target->children){
                if (item->type == FileType(directory))
                {
                    std::cout << "[dir]";
                }
                else{
                    std::cout << "[file]";
                }
                
                std::cout << item->name << ", ";
            }
            std::cout << std::endl;
        }

        void changeCurrent(std::string path){
            current = find(path);
        }

        std::string currentPath(){
            return current->name;
        }

};


void exmaple_tree(){
    FileSystem myFiles;
    std::string input, type, name, path;

    myFiles.add("./", FileType(directory), "dir1");
    myFiles.add("./", FileType(directory), "dir2");
    myFiles.add("./", FileType(directory), "dir3");
    myFiles.add("./dir2", FileType(file), "file1");

    do
    {
        std::cout << "\nenter command : " ;
        std::cin >> input;
        if (input == "add")
        {
            std::cout << "enter path, filename and type : ";
            std::cin >> path >> name >> type;
            if (type == "directory")
            {
                myFiles.add(path, FileType(directory), name);
            }else if(type == "file"){
                myFiles.add(path, FileType(file), name);
            }else{
                std::cout << "wrong input\n";
            }
            
        }else if(input == "cd"){
            std::cout << "enter path : " ;
            std::cin >> path;
            myFiles.changeCurrent(path);
        }
        else if(input == "list"){
            std::cout << "enter path : " ;
            std::cin >> path;
            myFiles.list(path);
        }
    } while (input != "quit");
    

}