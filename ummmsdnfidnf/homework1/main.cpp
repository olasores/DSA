#include <iostream>
#include <vector>
#include <utility>
#include <memory>


#include "GroceryItem.hpp"

int main() {
    std::vector<std::unique_ptr<GroceryItem>> groceryItems;
    // Read grocery item from standard input until end of file using std::cin 
    // store the grocery item in a dynamically allocated object 
    // store the grocery items in a standard vector
    // write the grocery item to standard output in reverse order using reverse iterators
    // delete the dynamically allocated objects

    std::cout << "Welcome to Kroger. Place grocery items into your shopping cart by entering each item's information." << '\n';
    std::cout << "Enclose string entries in quotes, separate fields with commas." << '\n';
    std::cout << R"(For example: \"00016000306707\", \"Betty Crocker\", \"Betty Crocker Double Chocolate Chunk Cookie Mix\", 17.19)" << '\n';
    std::cout << "Enter CTRL-Z (Windows) or CTRL-D (Linux) to quit." << '\n';
    
    
    // std::cout << "Enter the UPC, Product Brand, Product Name, and Price for eahc item." << '\n';
    

    while(true) {
        std::string input; 
        std::cout << "Enter the UPC, Product Brand, Product Name, and Price for each item." << '\n';
        if(std::getline(std::cin, input)) {
            auto newItem = std::make_unique<GroceryItem>(input);
            groceryItems.push_back(std::move(newItem));
            std::cout << "Items added to shopping cart: " << input << '\n';
        } else {
            break;
        }
    } 

    std::cout << "\nHere is an itemized list of the items in your shopping cart:" << '\n';
    // for (auto & groceryItem : std::ranges::reverse_view(groceryItems)) {
    //     std::cout << *groceryItem << '\n';
    // }
    for(auto it = groceryItems.rbegin(); it != groceryItems.rend(); ++it) {
        std::cout << **it << '\n';
    }

    groceryItems.clear();

    return 0;
}

