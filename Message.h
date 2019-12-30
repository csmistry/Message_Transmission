
#define MESSAGE_H
class Node {
    friend class Message;
    public:
        Node *get_next(); 
        std::string get_fragment();        
        Node( unsigned int id, std::string frag ); 
    private:
        unsigned int identifier; 
        std::string fragment; 
        Node *p_next; 
};
class Message {
    public:
        ~Message();
        void insert( unsigned int id, std::string fragment);
        void print_message();
    private:
        Node *head; 

};

