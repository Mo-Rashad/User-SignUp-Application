#include <iostream>
#include <string>
#include <array>
#include <limits>

int current_index = 0;
constexpr int max_size = 100;

std::array<std::string, max_size> users_names;
std::array<int, max_size> users_ages;

// Adding new user to the system
void addRecord(const std::string name,const int age)
{
  if (current_index < max_size)
  {
    users_names.at(current_index) = name;
    users_ages.at(current_index) = age;
    current_index++;
    std::cout << "\nUser record added successfully.\n";
  }
  else
  {
    std::cout << "Array is full, cannot append.\n";
  }
}
// Retrieving an exiting user in the system
void fetchRecord(const int id)
{
  if (id < current_index)
  {
    std::cout << "User Name: " << users_names[id] << '\n';
    std::cout << "User Age: " << users_ages[id] << '\n';
  }
  else
  {
    std::cout << "\nUser ID not valid." << '\n';
  }
}
// show the menu to the customer
void show_menu()
{
  std::cout << "\nPlease select an Option:\n";
  std::cout << "1. Add Record\n";
  std::cout << "2. Fetch Record\n";
  std::cout << "3. Quit\n";
}
// check Buffer failure avoiding infinity looping if data type not match
bool chk_buffer_fail()
{
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid type for your input.\n";
    return true;
  }
  else
    return false;
}



// the main application
int main()
{
  bool chk = true;
  int default_option = 1;
  int option = default_option;
  std::cout << "User Sign Up Application\n";
  while(chk)
  {
    show_menu();
    std::cout << "\nEnter option: ";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (option)
    {
      case 1: 
      {
        std::cout << "\nAdd User. Please enter user name and age:\n";
        std::string name;
        std::cout << "Name: ";
        std::getline(std::cin, name);
        int age = 0;
        while (true)
        {
          std::cout << "Age: ";
          std::cin >> age;
          if (!chk_buffer_fail()) break;
        }
        addRecord(name,age);
        break;
      }
      case 2: 
      {
        std::cout << "\nPlease enter user ID: ";
        std::cout << "\nUser ID: ";
        int id = 0;
        std::cin >> id;
        fetchRecord(id);
        break;
      }
      case 3:
        chk = false;
        break;
      default:
        std::cout << "\nPlease enter a valid option [1:3]\n";
        break;
    }
  }
}