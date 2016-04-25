#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include <sstream>
#include <iostream>

Contact *PhoneBook::SearchPhoneBook(string name)
{
    Contact* current = root;

    while (current != NULL){
        if(current->name > name){
            current = current->left;
        }
        else if(current->name < name){
            current = current->right;
        }
        else if(current->name == name){
            return current;
        }
    }


}
void PhoneBook::addContact(string name, string number, string email)
{
        if(root == NULL){
        root = new struct Contact(name, number, email);
    }
    else{
        PhoneBook* current = root;

        while (current != NULL){
            if(current->name >= name){
                if (current->left == NULL){
                    current->left = new struct Contact(name, number, email);
                    current->left->parent = current;
                    current = NULL;
                }
                else{
                    current = current->left;
                }
            }
            else if(current->name <= name){
                if (current->right == NULL){
                    current->right = new struct Contact(name, number, email);
                    current->right->parent = current;
                    current = NULL;
                }
                else{
                    current = current->right;
                }
            }
        }
    }
}
void PhoneBook::deleteContact(string name)
{
    Contact* current = root;
    current = searchMovieTree(title);
    if(current != NULL){
        if (current->right != NULL && current->left != NULL){
            Contact* node = current->right;

            while(node->left != NULL){
                node = node->left;
            }
            current->number = node->name;
            current->name = node->name;
            current->email = node->email;

            if(node->rightChild != NULL){
                if (node->parent->left == node)
                    node->parent->left = node->right;
                if (node->parent->right == node)
                    node->parent->right = node->right;
                node->right->parent = node->parent;
            }
            else{
                if (node->parent->left == node)
                    node->parent->left = NULL;
                if (node->parent->right == node)
                    node->parent->right = NULL;
            }

            delete node;
        }
        else if(current->right == NULL && current->left != NULL){
            if (current != root){
                if (current->parent->left == current){
                    current->parent->left = current->left;
                }
                else if (current->parent->right == current){
                    current->parent->right = current->left;
                }
            }
            else{
                root = current->left;
            }
            current->left->parent = current->parent;
            delete current;
        }
        else if(current->right != NULL && current->left == NULL){
            if (current != root){
                if (current->parent->left == current){
                    current->parent->left = current->right;
                }
                else if (current->parent->right == current){
                    current->parent->right = current->right;
                }
            }
            else{
                root = current->right;
            }
            current->right->parent = current->parent;
            delete current;
        }
        else{
            if (current != root){
                if (current->parent->left == current){
                    current->parent->left = NULL;
                }
                else if(current->parent->right == current){
                    current->parent->right = NULL;
                }
            }
            else{
                root = NULL;
            }
            delete current;
        }
    }
}


#endif
