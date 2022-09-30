#include <conio.h>
#include <iostream>
#include<windows.h>
#include "Functions.h"

using namespace std;

void Insert(Tree& tree)
{
	system("cls");
	cout << "Enter a quantity of elements to add: ";

	unsigned int count = 0U;
	cin >> count;

	for (unsigned int i = 0U; i < count; ++i)
	{
		Node* temp = new Node;

		cout << endl << "Enter an english word " << i + 1 << endl;
		cin >> temp->GetEnglish();

		cout << endl << "Enter a russian word " << i + 1 << endl;
		cin >> temp->GetRussian();

		tree.Insert(temp);
	}

}

void Print(const Tree& tree)
{
	system("cls");

	tree.Print(tree.GetRoot());

	_getch();
}

void PrintMenu()
{
	char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit \n6. Save file \n7. Exit\n ";

	system("cls");

	cout << menu;
}

void Remove(Tree& tree)
{
	system("cls");
	cout << "Enter an english word to remove:" << endl;

	char buffer[15] = {};
	cin >> buffer;

	Node* node = tree.Search(tree.GetRoot(), buffer);

	tree.Remove(node);
}

void Search(const Tree& tree)
{
	system("cls");
	cout << "Enter an english word to search:" << endl;

	char buffer[15] = {};
	cin >> buffer;

	Node* node = tree.Search(tree.GetRoot(), buffer);

	if (node != nullptr)
	{
		cout << node->GetRussian();
	}
	else
	{
		cout << "Word not found" << endl;
	}

	_getch();
}
void Edit(Tree& tree)
{
	system("cls");
	if (tree.GetRoot() == nullptr)
	{
		cout << "There is not a single word, enter the word first " << endl;
		Sleep(3000);
		Insert(tree);
		system("cls");
	}
	cout << "Enter the word for which you want to change the translation: ";
	char buffer[15] = {};
	cin >> buffer;
	Node* node = tree.Search(tree.GetRoot(), buffer);

	if (node != nullptr)
	{
		tree.Edit(tree.GetRoot(), buffer);
	}
	else
	{
		cout << "Word not found" << endl;
	}
	_getch();
}

void Save_file(Tree& tree)
{
	system("cls");

	tree.Save_file(tree.GetRoot());

	_getch();
}
