#include "stdafx.h"
#include "CppUnitTest.h"
#include "c:\Users\Vlast\source\repos\Algorithmslab1.1\Algorithmslab1.1\linkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(push_back) {
public:
	TEST_METHOD(push_back_int_first_elem) {
		List<int> *list = new List<int>();

		list->push_back(15);
		list->push_back(45);
		list->push_back(-20);
		list->push_back(0);

		Assert::AreEqual(list->at(0), 15);

		delete list;
	}
	TEST_METHOD(push_back_int_second_elem) {
		List<int> *list = new List<int>();

		list->push_back(15);
		list->push_back(45);
		list->push_back(-20);
		list->push_back(0);

		Assert::AreEqual(list->at(1), 45);

		delete list;
	}
	TEST_METHOD(push_back_int_third_elem) {
		List<int> *list = new List<int>();

		list->push_back(15);
		list->push_back(45);
		list->push_back(-20);
		list->push_back(0);

		Assert::AreEqual(list->at(2), -20);

		delete list;
	}
	TEST_METHOD(push_back_int_fourth_elem) {
		List<int> *list = new List<int>();

		list->push_back(15);
		list->push_back(45);
		list->push_back(-20);
		list->push_back(0);

		Assert::AreEqual(list->at(3), 0);

		delete list;
	}
	TEST_METHOD(push_back_char_first_elem) {
		List<char> *list = new List<char>();

		list->push_back('t');
		list->push_back('e');
		list->push_back('s');
		list->push_back('t');

		Assert::AreEqual(list->at(0), 't');

		delete list;
	}
	TEST_METHOD(push_back_char_second_elem) {
		List<char> *list = new List<char>();

		list->push_back('t');
		list->push_back('e');
		list->push_back('s');
		list->push_back('t');

		Assert::AreEqual(list->at(1), 'e');

		delete list;
	}
	TEST_METHOD(push_back_char_third_elem) {
		List<char> *list = new List<char>();

		list->push_back('t');
		list->push_back('e');
		list->push_back('s');
		list->push_back('t');

		Assert::AreEqual(list->at(2), 's');

		delete list;
	}
	TEST_METHOD(push_back_char_fourth_elem) {
		List<char> *list = new List<char>();

		list->push_back('t');
		list->push_back('e');
		list->push_back('s');
		list->push_back('t');

		Assert::AreEqual(list->at(3), 't');

		delete list;
	}
};

TEST_CLASS(push_front) {
public:
	TEST_METHOD(push_front_int_first_elem) {
		List<int> *list = new List<int>();

		list->push_front(15);
		list->push_front(45);
		list->push_front(-20);
		list->push_front(0);

		Assert::AreEqual(list->at(0), 0);

		delete list;
	}
	TEST_METHOD(push_front_int_second_elem) {
		List<int> *list = new List<int>();

		list->push_front(15);
		list->push_front(45);
		list->push_front(-20);
		list->push_front(0);

		Assert::AreEqual(list->at(1), -20);
		
		delete list;
	}
	TEST_METHOD(push_front_int_third_elem) {
		List<int> *list = new List<int>();

		list->push_front(15);
		list->push_front(45);
		list->push_front(-20);
		list->push_front(0);

		Assert::AreEqual(list->at(2), 45);

		delete list;
	}
	TEST_METHOD(push_front_int_fourth_elem) {
		List<int> *list = new List<int>();

		list->push_front(15);
		list->push_front(45);
		list->push_front(-20);
		list->push_front(0);

		Assert::AreEqual(list->at(3), 15);

		delete list;
	}
	TEST_METHOD(push_front_char_first_elem) {
		List<char> *list = new List<char>();

		list->push_front('t');
		list->push_front('e');
		list->push_front('s');
		list->push_front('t');

		Assert::AreEqual(list->at(0), 't');

		delete list;
	}
	TEST_METHOD(push_front_char_second_elem) {
		List<char> *list = new List<char>();

		list->push_front('t');
		list->push_front('e');
		list->push_front('s');
		list->push_front('t');

		Assert::AreEqual(list->at(1), 's');
		
		delete list;
	}
	TEST_METHOD(push_front_char_third_elem) {
		List<char> *list = new List<char>();

		list->push_front('t');
		list->push_front('e');
		list->push_front('s');
		list->push_front('t');

		Assert::AreEqual(list->at(2), 'e');

		delete list;
	}
	TEST_METHOD(push_front_char_fourth_elem) {
		List<char> *list = new List<char>();

		list->push_front('t');
		list->push_front('e');
		list->push_front('s');
		list->push_front('t');

		Assert::AreEqual(list->at(3), 't');

		delete list;
	}
};

TEST_CLASS(pop_back) {
public:
	TEST_METHOD(pop_back_int_first_elem_at) {
		List<int> *list = new List<int>({ 15, 20, 25 });
		
		list->pop_back();
		
		Assert::AreEqual(list->at(0), 15);

		delete list;
	}
	TEST_METHOD(pop_back_int_second_elem_at) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->pop_back();

		Assert::AreEqual(list->at(1), 20);

		delete list;
	}
	TEST_METHOD(pop_back_int_method_at_nonexistent_index) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->pop_back();

		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		delete list;
	}
	TEST_METHOD(pop_back_int_method_at_empty_list) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->pop_back();
		list->pop_back();
		list->pop_back();

		try {
			list->at(0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		delete list;
	}
	TEST_METHOD(pop_back_int_method_pop_back_empty_list) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->pop_back();
		list->pop_back();
		list->pop_back();

		try {
			list->pop_back();
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Pop back empty list");
		}

		delete list;
	}
	TEST_METHOD(pop_back_char_first_elem_at) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->pop_back();
		Assert::AreEqual(list->at(0), 'a');

		delete list;
	}
	TEST_METHOD(pop_back_char_second_elem_at) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->pop_back();
		Assert::AreEqual(list->at(1), 'b');

		delete list;
	}
	TEST_METHOD(pop_back_char_method_at_nonexistent_index) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->pop_back();

		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		delete list;
	}
	TEST_METHOD(pop_back_char_method_at_empty_list) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->pop_back();
		list->pop_back();
		list->pop_back();

		try {
			list->at(0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		delete list;
	}
	TEST_METHOD(pop_back_char_method_pop_back_at_nonexistent_elem) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->pop_back();

		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->pop_back();
		Assert::AreEqual(list->at(0), 'a');
		try {
			list->at(1);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->pop_back();
		try {
			list->at(0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		try {
			list->pop_back();
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Pop back empty list");
		}

		delete list;
	}

};

TEST_CLASS(pop_front) {
public:
	TEST_METHOD(pop_front_int) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->pop_front();
		Assert::AreEqual(list->at(0), 20);
		Assert::AreEqual(list->at(1), 25);
		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->pop_front();
		Assert::AreEqual(list->at(0), 25);
		try {
			list->at(1);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->pop_front();
		try {
			list->at(0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		try {
			list->pop_front();
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Pop front empty list");
		}

		delete list;
	}
	TEST_METHOD(pop_front_char) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->pop_front();
		Assert::AreEqual(list->at(0), 'b');
		Assert::AreEqual(list->at(1), 'c');
		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->pop_front();
		Assert::AreEqual(list->at(0), 'c');
		try {
			list->at(1);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->pop_front();
		try {
			list->at(0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		try {
			list->pop_front();
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Pop front empty list");
		}

		delete list;
	}
};

TEST_CLASS(get_size) { 
public:
	TEST_METHOD(get_size_int) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		Assert::AreEqual(list->get_size(), size_t(3));
		list->pop_back();
		Assert::AreEqual(list->get_size(), size_t(2));
		list->pop_back();
		Assert::AreEqual(list->get_size(), size_t(1));
		list->pop_back();
		Assert::AreEqual(list->get_size(), size_t(0));

		delete list;
	}
	TEST_METHOD(get_size_char) {
		List<char> *list = new List<char>({ 15, 20, 25 });

		Assert::AreEqual(list->get_size(), size_t(3));
		list->pop_back();
		Assert::AreEqual(list->get_size(), size_t(2));
		list->pop_back();
		Assert::AreEqual(list->get_size(), size_t(1));
		list->pop_back();
		Assert::AreEqual(list->get_size(), size_t(0));

		delete list;
	}
};

TEST_CLASS(insert) {
public:
	TEST_METHOD(insert_int) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->insert(7, 0);
		Assert::AreEqual(list->at(0), 7);
		Assert::AreEqual(list->at(1), 15);
		Assert::AreEqual(list->at(2), 20);
		Assert::AreEqual(list->at(3), 25);

		list->insert(17, 2);
		Assert::AreEqual(list->at(0), 7);
		Assert::AreEqual(list->at(1), 15);
		Assert::AreEqual(list->at(2), 17);
		Assert::AreEqual(list->at(3), 20);
		Assert::AreEqual(list->at(4), 25);

		list->insert(22, 4);
		Assert::AreEqual(list->at(0), 7);
		Assert::AreEqual(list->at(1), 15);
		Assert::AreEqual(list->at(2), 17);
		Assert::AreEqual(list->at(3), 20);
		Assert::AreEqual(list->at(4), 22);
		Assert::AreEqual(list->at(5), 25);

		try {
			list->insert(-2, -1);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "Insert negative argument");
		}

		try {
			list->insert(50, 55);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Insert nonexistent index");
		}

		List<int> *emptyList = new List<int>();
		try {
			emptyList->insert(5, 0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Insert empty list");
		}

		delete list;
		delete emptyList;
	}
	TEST_METHOD(insert_char) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->insert('d', 0);
		Assert::AreEqual(list->at(0), 'd');
		Assert::AreEqual(list->at(1), 'a');

		list->insert('e', 2);
		Assert::AreEqual(list->at(0), 'd');
		Assert::AreEqual(list->at(1), 'a');
		Assert::AreEqual(list->at(2), 'e');
		Assert::AreEqual(list->at(3), 'b');

		list->insert('f', 4);
		Assert::AreEqual(list->at(0), 'd');
		Assert::AreEqual(list->at(1), 'a');
		Assert::AreEqual(list->at(2), 'e');
		Assert::AreEqual(list->at(3), 'b');
		Assert::AreEqual(list->at(4), 'f');
		Assert::AreEqual(list->at(5), 'c');

		try {
			list->insert('g', -1);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "Insert negative argument");
		}

		try {
			list->insert('h', 55);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Insert nonexistent index");
		}

		List<char> *emptyList = new List<char>();
		try {
			emptyList->insert('i', 0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Insert empty list");
		}

		delete list;
		delete emptyList;
	}
};

TEST_CLASS(at) {
public:
	TEST_METHOD(at_int) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		Assert::AreEqual(list->at(0), 15);
		Assert::AreEqual(list->at(1), 20);
		Assert::AreEqual(list->at(2), 25);

		try {
			list->at(-2);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "At negative argument");
		}

		try {
			list->at(50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		List<int> *emptyList = new List<int>();
		try {
			emptyList->at(5);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		delete list;
		delete emptyList;
	}
	TEST_METHOD(at_char) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		Assert::AreEqual(list->at(0), 'a');
		Assert::AreEqual(list->at(1), 'b');
		Assert::AreEqual(list->at(2), 'c');

		try {
			list->at(-1);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "At negative argument");
		}

		try {
			list->at(55);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		List<char> *emptyList = new List<char>();
		try {
			emptyList->at(0);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At empty list");
		}

		delete list;
		delete emptyList;
	}
};

TEST_CLASS(list_remove) {
public:
	TEST_METHOD(list_remove_int) {
		List<int> *list = new List<int>({ 15, 20, 25, 30 });

		list->remove(0);
		Assert::AreEqual(list->at(0), 20);
		Assert::AreEqual(list->at(1), 25);
		Assert::AreEqual(list->at(2), 30);
		
		try {
			list->at(55);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->remove(1);
		Assert::AreEqual(list->at(0), 20);
		Assert::AreEqual(list->at(1), 30);
		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->remove(1);
		Assert::AreEqual(list->at(0), 20);
		try {
			list->at(1);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		try {
			list->remove(-2);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "Remove negative argument");
		}

		try {
			list->remove(50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Remove nonexistent index");
		}

		List<int> *emptyList = new List<int>();
		try {
			emptyList->remove(5);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Remove empty list");
		}

		delete list;
		delete emptyList;
	}
	TEST_METHOD(list_remove_char) {
		List<char> *list = new List<char>({ 'a', 'b', 'c', 'd' });

		list->remove(0);
		Assert::AreEqual(list->at(0), 'b');
		Assert::AreEqual(list->at(1), 'c');
		Assert::AreEqual(list->at(2), 'd');
		try {
			list->at(3);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->remove(1);
		Assert::AreEqual(list->at(0), 'b');
		Assert::AreEqual(list->at(1), 'd');
		try {
			list->at(2);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		list->remove(1);
		Assert::AreEqual(list->at(0), 'b');
		try {
			list->at(1);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "At nonexistent index");
		}

		try {
			list->remove(-2);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "Remove negative argument");
		}

		try {
			list->remove(50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Remove nonexistent index");
		}

		List<char> *emptyList = new List<char>();
		try {
			emptyList->remove(5);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Remove empty list");
		}

		delete list;
		delete emptyList;
	}
};

TEST_CLASS(set) {
public:
	TEST_METHOD(set_int) {
		List<int> *list = new List<int>({ 15, 20, 25 });

		list->set(51, 0);
		Assert::AreEqual(list->at(0), 51);
		list->set(2, 1);
		Assert::AreEqual(list->at(1), 2);
		list->set(52, 2);
		Assert::AreEqual(list->at(2), 52);

		try {
			list->set(-2, -2);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "Set negative argument");
		}

		try {
			list->set(50, 50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Set nonexistent index");
		}

		List<int> *emptyList = new List<int>();
		try {
			emptyList->set(2, 50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Set empty list");
		}

		delete list;
		delete emptyList;
	}
	TEST_METHOD(set_char) {
		List<char> *list = new List<char>({ 'a', 'b', 'c' });

		list->set('d', 0);
		Assert::AreEqual(list->at(0), 'd');
		list->set('e', 1);
		Assert::AreEqual(list->at(1), 'e');
		list->set('f', 2);
		Assert::AreEqual(list->at(2), 'f');

		try {
			list->set(-2, -2);
			Assert::Fail();
		}
		catch (const std::invalid_argument& e) {
			Assert::AreEqual(e.what(), "Set negative argument");
		}

		try {
			list->set(50, 50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Set nonexistent index");
		}

		List<char> *emptyList = new List<char>();
		try {
			emptyList->set(2, 50);
			Assert::Fail();
		}
		catch (const std::out_of_range& e) {
			Assert::AreEqual(e.what(), "Set empty list");
		}

		delete list;
		delete emptyList;
	}
};

TEST_CLASS(isEmpty) {
public:
	TEST_METHOD(isEmpty_int) {
		List<int> *list = new List<int>({ 15, 20, 25 });
		List<int> *emptyList = new List<int>();

		Assert::IsFalse(list->isEmpty());
		Assert::IsTrue(emptyList->isEmpty());

		delete list;
		delete emptyList;
	}
	TEST_METHOD(isEmpty_char) {
		List<char> *list = new List<char>({ 15, 20, 25 });
		List<char> *emptyList = new List<char>();

		Assert::IsFalse(list->isEmpty());
		Assert::IsTrue(emptyList->isEmpty());

		delete list;
		delete emptyList;
	}
};