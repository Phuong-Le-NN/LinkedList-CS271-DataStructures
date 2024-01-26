//	
//  test_set.cpp
//  CS 271 Set Project: Example Test File
//  Kian Jennings and Phuong Le
//  Format and time_test created by Dr. Stacey Truex
//
#include <iostream>
#include "set.cpp"
#include "string"

void test_insert() {
    //test int
    try {
        Set<int> s;
        s.insert(0);
        string set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2);
        s.insert(-1);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << endl;
        }
        s.insert('L');
        set_str = s.to_string();
        if (s.to_string() != "76 -1 2 0") {
            cout << "Incorrect insert result. Expected 76 -1 2 0 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
    //test string
        try {
        Set<string> s;
        s.insert("string1");
        s.insert("string2");
        s.insert("string3");
        
        string set_str = s.to_string();
        if (set_str != "string3 string2 string1") {
            cout << "Incorrect insert result for string. Expected string3 string2 string1 but got : " << set_str << endl;
        }
        
    } catch (exception& e) {
        cerr << "Error inserting string into set : " << e.what() << endl;
    }
    //test float
    try {
        Set<float> s;
        s.insert(0);
        string set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2.7);
        s.insert(-1.5);
        set_str = s.to_string();
        if (s.to_string() != "-1.5 2.7 0") {
            cout << "Incorrect insert result. Expected -1.5 2.7 0 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
    //test char
    try {
        Set<char> s;
        s.insert('a');
        string set_str = s.to_string();
        if (s.to_string() != "a") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert('b');
        s.insert('c');
        set_str = s.to_string();
        if (s.to_string() != "c b a") {
            cout << "Incorrect insert result. Expected c b a but got : " << set_str << endl;
        }
        s.insert('L');
        set_str = s.to_string();
        if (s.to_string() != "L c b a") {
            cout << "Incorrect insert result. Expected L c b a but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
}

void test_remove() {
    //test int
    try {
        Set<int> s;
        s.remove(1); //try remove from an empty list
        string set_str = s.to_string();
        if (s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
        s.insert(-1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(5);
        set_str = s.to_string();
        if (s.to_string() != "4 3 2 -1") {
            cout << "Incorrect remove result. Expected 4 3 2 -1 but got : " << set_str << endl;
        }
        s.remove(4); //try removing last element
        set_str = s.to_string();
        if(s.to_string() != "3 2 -1") {
            cout << "Incorrect remove result. Expected 3 2 -1 but got : " << set_str << endl;
        }
        s.remove(2); //try removing second to last element
        set_str = s.to_string();
        if(s.to_string() != "3 -1") {
            cout << "Incorrect remove result. Expected 3 -1 but got : " << set_str << endl;
        }
        s.remove(7); //try removing nonexistent element
        set_str = s.to_string();
        if(s.to_string() != "3 -1") {
            cout << "Incorrect remove result. Expected 3 -1 but got : " << set_str << endl;
        }
        s.remove(-1); //try removing first element
        set_str = s.to_string();
        if(s.to_string() != "3") {
            cout << "Incorrect remove result. Expected 3 but got : " << set_str << endl;
        }
        s.remove(3); //try removing the only element
        set_str = s.to_string();
        if(s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
    //test string
    try {
        Set<string> s;
        s.remove("string"); //try remove from an empty list
        string set_str = s.to_string();
        if (s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
        s.insert("stringa");
        s.insert("stringb");
        s.insert("stringc");
        s.insert("stringd");
        s.remove("stringd");
        set_str = s.to_string();
        if (s.to_string() != "stringc stringb stringa") {
            cout << "Incorrect remove result. Expected \"stringc stringb stringa\" but got : " << set_str << endl;
        }
        s.remove("stringc"); //try removing last element
        set_str = s.to_string();
        if(s.to_string() != "stringb stringa") {
            cout << "Incorrect remove result. Expected \"stringb stringa\" but got : " << set_str << endl;
        }
        s.remove("stringa"); //try removing second to last element
        set_str = s.to_string();
        if(s.to_string() != "stringb") {
            cout << "Incorrect remove result. Expected \"stringb\" but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
    //test int
    try {
        Set<int> s;
        s.remove(1); //try remove from an empty list
        string set_str = s.to_string();
        if (s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
        s.insert(-1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(5);
        set_str = s.to_string();
        if (s.to_string() != "4 3 2 -1") {
            cout << "Incorrect remove result. Expected 4 3 2 -1 but got : " << set_str << endl;
        }
        s.remove(4); //try removing last element
        set_str = s.to_string();
        if(s.to_string() != "3 2 -1") {
            cout << "Incorrect remove result. Expected 3 2 -1 but got : " << set_str << endl;
        }
        s.remove(2); //try removing second to last element
        set_str = s.to_string();
        if(s.to_string() != "3 -1") {
            cout << "Incorrect remove result. Expected 3 -1 but got : " << set_str << endl;
        }
        s.remove(7); //try removing nonexistent element
        set_str = s.to_string();
        if(s.to_string() != "3 -1") {
            cout << "Incorrect remove result. Expected 3 -1 but got : " << set_str << endl;
        }
        s.remove(-1); //try removing first element
        set_str = s.to_string();
        if(s.to_string() != "3") {
            cout << "Incorrect remove result. Expected 3 but got : " << set_str << endl;
        }
        s.remove(3); //try removing the only element
        set_str = s.to_string();
        if(s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
    //test int
    try {
        Set<int> s;
        s.remove(1); //try remove from an empty list
        string set_str = s.to_string();
        if (s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
        s.insert(-1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(5);
        set_str = s.to_string();
        if (s.to_string() != "4 3 2 -1") {
            cout << "Incorrect remove result. Expected 4 3 2 -1 but got : " << set_str << endl;
        }
        s.remove(4); //try removing last element
        set_str = s.to_string();
        if(s.to_string() != "3 2 -1") {
            cout << "Incorrect remove result. Expected 3 2 -1 but got : " << set_str << endl;
        }
        s.remove(2); //try removing second to last element
        set_str = s.to_string();
        if(s.to_string() != "3 -1") {
            cout << "Incorrect remove result. Expected 3 -1 but got : " << set_str << endl;
        }
        s.remove(7); //try removing nonexistent element
        set_str = s.to_string();
        if(s.to_string() != "3 -1") {
            cout << "Incorrect remove result. Expected 3 -1 but got : " << set_str << endl;
        }
        s.remove(-1); //try removing first element
        set_str = s.to_string();
        if(s.to_string() != "3") {
            cout << "Incorrect remove result. Expected 3 but got : " << set_str << endl;
        }
        s.remove(3); //try removing the only element
        set_str = s.to_string();
        if(s.to_string() != "") {
            cout << "Incorrect remove result. Expected empty set but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6);
        c = s.cardinality();
        if(c != 1) {
            cout << "Incorrect cardinality. Expected 1 but got : " << c << endl;
        }
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
        s.remove(4);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
        s.remove(6);
        s.remove(5);
        s.remove(3);
        s.remove(1);
        c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    try {
        Set<int> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert(1);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.insert(2);
        s.remove(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(1);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
    try {
        Set<int> s;
        if(s.contains(5))//test empty set 
        {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        s.insert(1); //test set with 1 element
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(1)) {
            cout << "Incorrectly identified existing element as NOT in the set " << s.to_string() << endl;
        }
        s.insert(2);
        s.insert(3);
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(2)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }
        s.insert('z'); //test if program can corece char into int when inserting and differentiate char and int when check contain
        if(!s.contains('z')) {
            cout << "Incorrectly identified z as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in se : " << e.what() << endl;
    }
}

void test_equality() {
    try {
        Set<int> s;
        Set<int> t;
        Set<int> em;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        s.insert('z');
        s.insert(3);
        t.insert(1);
        t.insert(122);
        t.insert(3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        if(s==em) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << em.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(3);
        t.insert(7);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(7);
        s.insert(3);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(10);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(11);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }
        
    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str;
        set_str = (s+t).to_string();
        if(set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(2);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "2 1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        t.insert(6);
        set_str = (s+t).to_string();
        if(set_str != "2 1 6") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << endl;
        }
        t.insert(8);
        t.insert(10);
        set_str = (s+t).to_string();
        if(set_str != "2 1 6 8 10") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 8 10 but instead got : " << set_str << endl;
        }
        s.insert(7);
        s.insert(9);
        set_str = (s+t).to_string();
        if(set_str != "7 9 2 1 6 8 10") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 7 9 2 1 6 8 10 but instead got : " << set_str << endl;
        }
        Set<string> l;
        Set<string> l2;
        l.insert("Hello");
        l.insert("World");
        l2.insert("Good");
        l2.insert("World");
        set_str = (l+l2).to_string();
        if(set_str != "Hello Good World") {
            cout << "Set " << l.to_string() << " + Set " << l2.to_string() << " was expected to be Hello Good World but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        Set<int> em;
        string set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s&t).to_string();
        if(set_str != "1 2") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl;
        }
        t.insert(3);
        t.insert(4);
        set_str = (t&em).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and the empty set" << " was expected to be empty set but instead got : " << set_str << endl;
        }
        Set<string> l;
        Set<string> l2;
        l.insert("Hello");
        l.insert("World");
        l2.insert("Good");
        l2.insert("World");
        set_str = (l&l2).to_string();
        if(set_str != "World") {
            cout << "Set " << l.to_string() << " & Set " << l2.to_string() << " was expected to be World but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        Set<int> em;
        string set_str = (s-t).to_string();
        if(set_str != "") { //check for 2 empty sets
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s-t).to_string();
        if(set_str != "1 2") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        set_str = (t-s).to_string();
        if(set_str != "6") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 6 but instead got : " << set_str << endl;
        }
        set_str = (t-em).to_string();
        if(set_str != "6 2 1") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 6 2 1 but instead got : " << set_str << endl;
        }
        Set<string> l;
        Set<string> l2;
        l.insert("Hello");
        l.insert("World");
        l2.insert("Good");
        l2.insert("Place");
        set_str = (l-l2).to_string();
        if(set_str != "Hello World") {
            cout << "Set " << l.to_string() << " \\ Set " << l2.to_string() << " was expected to be Hello World but instead got : " << set_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void time_test() {
    Set<int> S;
    // TO-DO: generate large set
    Set<int> T;
    // TO-DO: generate large set
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    S.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.remove(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.cardinality();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    S.empty();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    val = rand()%100000;
    begin = std::chrono::high_resolution_clock::now();
    //bool r = S.contains(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    //r = (S==T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    //r = (S<=T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    Set<int> U = (S+T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S&T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S-T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;

}
int main() {
    test_insert();
    cout << "test_insert succeeded" << endl;
    test_remove();
    cout << "test_remove succeeded" << endl;
    test_cardinality();
    cout << "test_cardinality succeeded" << endl;
    test_empty();
    cout << "test_empty succeeded" << endl;
    test_contains();
    cout << "test_contains succeeded" << endl;
    test_equality();
    cout << "test_equality succeeded" << endl;
    test_subset();
    cout << "test_subset succeeded" << endl;
    test_union();
    cout << "test_union succeeded" << endl;
    test_intersection();
    cout << "test_intersection succeeded" << endl;
    test_diff();
    cout << "test_diff succeeded" << endl;

    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}
