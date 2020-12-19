// Copyright 2020 Rinat <rinamuka4@gmail.com

#include <gtest/gtest.h>

#include "SharedPtr.hpp"
TEST(Example, EmptyTest) { EXPECT_TRUE(true); }

/*TEST(SharedPtr, constructor1) {
  SharedPtr<int> constr1;
  ASSERT_EQ(*constr1, nullptr);
}*/

TEST(SharedPtr, constructorWithArgument) {
  int a = 8;
  SharedPtr<int> var(&a);
  ASSERT_EQ(*var, a);
}

TEST(SharedPtr, constructorWithLValLink) {
  int a = 8;
  SharedPtr var(&a);
  SharedPtr l(var);
  ASSERT_EQ(var.use_count(), 2);
}

TEST(SharedPtr, constructorWithRValLink) {
  int a = 9;
  SharedPtr var(&a);
  SharedPtr r(std::move(var));
  ASSERT_EQ(var.use_count(), 2);
}

TEST(SharedPtr, isMoveConstr){
  ASSERT_EQ(std::is_move_constructible<SharedPtr<int>>::value,true);
}

TEST(SharedPtr, isMoveAssign){
  ASSERT_EQ(std::is_move_assignable<SharedPtr<int>>::value,true);
}

TEST(SharedPtr, operatorRavnoWithLValLink){
  int a = 32;
  SharedPtr var(&a);
  SharedPtr var1 = var;
  ASSERT_EQ(var.use_count(),2);
}


TEST(ShredPtr, operatorRavnoWithRValLink){
  int a = 12;
  SharedPtr var(&a);
  SharedPtr var1 = std::move(var);
  ASSERT_EQ(var.use_count(),2);
}




TEST(SharedPtr, funcSwap){
  int a = 1;
  int b = 2;
  SharedPtr<int> A(&a);
  SharedPtr<int> B(&b);
  B.swap(A);
  ASSERT_EQ(*B, 1);
}

/*TEST(SharedPtr, funcReset){
  int a = 88;
  SharedPtr var(&a);
  var.reset();
  ASSERT_EQ(*var.get(), nullptr);
}*/



