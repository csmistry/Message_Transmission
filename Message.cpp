//============================================================================
// Name        : Message.cpp
// Author      : Chintan Mistry
// Version     :1.3
// Description : Communication between classes to reveal a full message that was sent in fragments
//============================================================================

#include <iostream>
#include<string>
#include "Message.h"


int main();
//Node class initializes the needed parameters for a node
Node::Node(unsigned int id, std::string frag){
	 identifier=id;
	 fragment=frag;
	p_next=nullptr;
}
std::string Node::get_fragment(){
return fragment;
}

//return address of next node
Node *Node::get_next(){
	return p_next;
}

Message::Message(){
	head=nullptr;
}

//deallocates each node
Message::~Message(){
	while(head!=nullptr){
		Node *previous_list{head};
		Node *p_current{head};
		head = p_current->get_next();
		delete previous_list;
	}

}
void Message::insert(unsigned int id, std::string fragment){
	if(head==nullptr){
		//If the list is empty set p_next of new node equal to head and set head equal to the new node
		Node *p_new_node= new Node(id, fragment);
		p_new_node->p_next =head;
		head= p_new_node;
	}else{
		Node *p_new_node= new Node(id, fragment);
		//If list is not empty, first compare the identifier values and arrange them in ascending order
		if(p_new_node->identifier < head->identifier){
			p_new_node->p_next= head;
			head= p_new_node;
		}else{
			for(Node *p_current{head}; p_current!=p_new_node; p_current= p_current->get_next() ){
				if(p_current->p_next == nullptr){
					p_current->p_next= p_new_node;
					p_new_node=nullptr;
				}else if(p_current->p_next->identifier > id){
					p_new_node->p_next = p_current->p_next;
					p_current->p_next = p_new_node;

				}
			}
		}
	}
}

// Print function to print received messages
void Message::print_message(){
	unsigned int count{0};
	Node *p_current{head};
	Node *p_EOT{nullptr};
	if(p_current != nullptr){
		count = p_current->identifier;
		for(std::size_t i{0}; i<count; i++){
			std::cout << "..." << " ";
		}
	}

	for(Node *p_current{head}; p_current!=nullptr; p_current= p_current->get_next() ){
		if(p_current->fragment == "EOT"){
			p_EOT= p_current;
		}
		if(p_current->fragment != "EOT"){
		std::cout << p_current->get_fragment() << " ";
		}
		if(p_current->p_next != nullptr){
			for(std::size_t k{p_current->identifier+1}; k<(p_current->p_next->identifier); ++k){
				if(p_current->p_next != nullptr){
				std::cout << "..." <<" ";
				}else{
					std::cout << "...";
				}
				}
			}
		}
		if(p_EOT== nullptr){
			std::cout << "???";
		}
		std::cout << std::endl;
}


int main() {
	Message Sender;
	std::string input_frag;
	signed int input;

	while(input != -2){
		std::cin >> input;
		if(input == -1){
			Sender.print_message();
		}else if(input >= 0){
			std::cin >> input_frag;
			Sender.insert(input, input_frag);
		}
	}
	return 0;
}
