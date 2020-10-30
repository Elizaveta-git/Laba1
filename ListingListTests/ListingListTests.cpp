#include <stdexcept>
#include "pch.h"
#include "CppUnitTest.h"
#include "..\laba1\LinkedList.h"
#include "..\laba1\LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListingListTests
{
	TEST_CLASS(ListingListTests)
	{
	public:
		List * lst;
		
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst = new List();
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete lst;
		}

		//////////METHOD//AT//////////
		TEST_METHOD(at_correct_index)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			Assert::AreEqual(lst->at(1), 2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			lst->push_back(1);
			lst->push_back(2);
			try 
			{
				lst->at(2);
			}
			catch (std::out_of_range e) 
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(at_empty_list)
		{
			lst->clear();
			try 
			{
				lst->at(3);
			}
			catch (std::out_of_range e) 
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}

		//////////METHOD//PUSH//BACK//////////
		TEST_METHOD(push_back_1)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			Assert::AreEqual(lst->at(0), 1);
			Assert::AreEqual(lst->at(1), 10);
			Assert::AreEqual(lst->at(2), 100);
		}
		TEST_METHOD(push_back_EmptyList)
		{
			lst->clear();
			try
			{
				lst->at(0);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
			lst->push_back(1);
			Assert::AreEqual(lst->at(0), 1);
		}

		//////////METHOD//PUSH//FRONT//////////
		TEST_METHOD(push_front_1)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_front(100);
			Assert::AreEqual(lst->at(0), 100);
			Assert::AreEqual(lst->at(1), 1);
			Assert::AreEqual(lst->at(2), 10);
		}
		TEST_METHOD(push_front_EmptyList)
		{
			lst->clear();
			try
			{
				lst->at(0);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
			lst->push_front(1);
			Assert::AreEqual(lst->at(0), 1);
		}

		//////////METHOD//INSERT//////////
		TEST_METHOD(insert_end)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			Assert::AreEqual(lst->at(2), 100);
			lst->insert(1000, 2);
			Assert::AreEqual(lst->at(2), 1000);
			Assert::AreEqual(lst->at(3), 100);
		}
		TEST_METHOD(insert_first)
		{
			lst->push_back(10);
			lst->push_back(100);
			lst->push_back(1000);
			Assert::AreEqual(lst->at(0), 10);
			lst->insert(1, 0);
			Assert::AreEqual(lst->at(0), 1);
			Assert::AreEqual(lst->at(3), 1000);
		}
		TEST_METHOD(insert_middle)
		{
			lst->push_back(1);
			lst->push_back(100);
			lst->push_back(1000);
			Assert::AreEqual(lst->at(1), 100);
			lst->insert(10, 1);
			Assert::AreEqual(lst->at(1), 10);
			Assert::AreEqual(lst->at(2), 100);
			Assert::AreEqual(lst->at(3), 1000);
		}
		TEST_METHOD(insert_emptyList)
		{
			lst->clear();
			try
			{
				lst->insert(1, 0);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}
		TEST_METHOD(insert_incorrect_index)
		{
			lst->push_back(1);
			lst->push_back(100);
			lst->push_back(1000);
			try
			{
				lst->insert(10000, 10);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		//////////METHOD//POP//FRONT//////////
		TEST_METHOD(PopFront_)
		{
			lst->push_back(1);
			lst->push_back(100);
			lst->push_back(1000);
			lst->pop_front();
			Assert::AreEqual(lst->at(0), 100);
			try
			{
				lst->at(2);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(PopFront_emptyList)
		{
			lst->clear();
			try
			{
				lst->pop_front();
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}

		//////////METHOD//POP//BACK//////////
		TEST_METHOD(PopBack_)
		{
			lst->push_back(1);
			lst->push_back(100);
			lst->push_back(1000);
			Assert::AreEqual(lst->at(2), 1000);
			lst->pop_back();
			Assert::AreEqual(lst->at(1), 100);
			try
			{
				lst->at(2);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(PopBack_emptyList)
		{
			lst->clear();
			try
			{
				lst->pop_back();
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}

		//////////METHOD//REMOVE//////////
		TEST_METHOD(remove_end)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			lst->remove(2);
			Assert::AreEqual(lst->at(1), 10);
			try
			{
				lst->at(2);
			}
				catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
			
		}
		TEST_METHOD(remove_first)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			lst->remove(0);
			Assert::AreEqual(lst->at(0), 10);
			try
			{
				lst->at(2);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(remove_middle)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			lst->remove(1);
			Assert::AreEqual(lst->at(1), 100);
			try
			{
				lst->at(2);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(remove_emptyList)
		{
			lst->clear();
			try
			{
				lst->remove(2);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}

		//////////METHOD//SET//////////
		TEST_METHOD(set_emptyList)
		{
			lst->clear();
			try
			{
				lst->set(100, 0);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}
		TEST_METHOD(set_middle)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			lst->set(200, 1);
			Assert::AreEqual(lst->at(1), 200);
		}
		TEST_METHOD(set_incorrect_index)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			try
			{
				lst->set(100, 10);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		//////////METHOD//SWAP//////////
		TEST_METHOD(swap_emptyList)
		{
			lst->clear();
			try
			{
				lst->swap(2,10);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}
		TEST_METHOD(swap_middle)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			lst->swap(0, 2);
			Assert::AreEqual(lst->at(0), 100);
			Assert::AreEqual(lst->at(2), 1);
		}
		TEST_METHOD(swap_equality)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			try
			{
				lst->swap(0, 0);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Iindexes are equal", e.what());
			}
		}
		TEST_METHOD(swap_incorrect_index)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			try
			{
				lst->swap(0, 10);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		//////////METHOD//GET//SIZE//////////
		TEST_METHOD(getSize_emptyList)
		{
			lst->clear();
			try
			{
				lst->get_size();
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The list is empty", e.what());
			}
		}
		TEST_METHOD(getSize)
		{
			lst->push_back(1);
			lst->push_back(10);
			lst->push_back(100);
			Assert::AreEqual(lst->get_size(), size_t(3));
		}

	};
}
