#ifndef HASHTABLE_OA_HPP
#define HASHTABLE_OA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

class HashTableOA {
    private:
        int number_of_elements;
        int size;
        float load_factor; 
        typedef pair<int, string> student;
        vector<student *> table;
    public:
        HashTableOA() {
            size = 50;
            number_of_elements = 0;
            load_factor = 0;

            vector<student *> table1(size, nullptr);
            this->table = table1;
        }

        ~HashTableOA() {};

        int hashFunc(int sindex) {
            return sindex % size;
        }

        void reHash() {
            size += int((number_of_elements / 0.6) + 1);
            vector<student *> temp(size);

            for (auto i : table) {
                if (i != nullptr) temp[hashFunc(i->first)] = i;
            }

            table = temp;
        }

        void add(int sindex, string name) {
            student *temp = new student;
            temp->first = sindex;
            temp->second = name;

            int index = hashFunc(temp->first);
            insert(temp, index);
        }

        void insert(student *stu, int index) {
            if (table[index] == nullptr) {
                table[index] = stu;
                number_of_elements++;
                load_factor = number_of_elements / size;

                if (load_factor > 0.75)
                    reHash();
            }
            else {
                if (table[index]->first == stu->first) table[index] = stu;
                else {
                    index++;
                    if (index >= size) table.resize(size++);
                    insert(stu, index);
                }
            }
        }

        void showElements() {
            for (int i = 0; i < size; i++) {
                if (table[i] != nullptr) {
                    cout << i << " | " << "Index: " << table[i]->first << " Student: " << table[i]->second << endl;
                }
            }
        }

        void searchForElement(int sindex) {
            auto start = high_resolution_clock::now();
            int index = hashFunc(sindex);

            for (; table[index]->first != sindex; index++);
            cout << "Index: " << table[index]->first << " Name: " << table[index]->second << endl;

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "(Czas wykonania funkcji: "<< duration.count() << " mikrosekund)" << endl;
        }
};

#endif