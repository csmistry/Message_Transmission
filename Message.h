
#define MESSAGE_H
class Node {
    friend class Message;
    public:
        //returns next node in the linked list
        Node *get_next(); 
        //Returns the string representing the fragment stored in this packet.
        std::string get_fragment(); 
        //Node constructor
        Node( unsigned int id, std::string frag ); 
    private:
        unsigned int identifier; 
        std::string fragment; 
        //pointer to the next node
        Node *p_next; 
};
class Message {
    public:
        //default constructor will set the head to null
        Message();
     //destructor to deallocate set nodes
        ~Message();
    //Inserts a node in the linked list, with packet information provided as parameters. 
        void insert( unsigned int id, std::string fragment);
        void print_message();
    private:
    //pointer to the first packet of the message.
        Node *head; 

};

