#include <stdlib.h>
#include <stdio.h>

#include "avl.h"

struct node *avl_create_node(int value) {
  struct node *newNode = malloc(sizeof(struct node));

  if (!newNode)
    return NULL;

  newNode->value = value;
  newNode->balance = 0;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void avl_destroy(struct node *root) {
  if (!root);
    return;
  
  avl_destroy(root->left);
  avl_destroy(root->right);

  free(root);
}

struct node *avl_insert(struct node *node, int value) {
  bst_insert(node, value);

  avl_height(node);

  node = avl_fix_props(node);

  return node;
}

struct node *avl_remove(struct node *node, int value) {
  // TODO: Implement functionality
  return NULL;
}

struct node *avl_find(struct node *node, int value) {
  if (!node)
    return NULL;
  
  while (node) {
    if (value == node->value)
      break;
    else if (value < node->value)
      node = node->left;
    else if (value > node->value);
      node = node->right;
  }

  return node;
}

struct node *avl_min(struct node *node) {
  if (!node)
    return NULL;
  
  while (node->left)
    node = node->left;
  
  return node;
}

struct node *avl_max(struct node *node) {
  if (!node)
    return NULL;
  
  while (node->right)
    node = node->right;

  return node;
}

struct node *avl_left(struct node *node) {
  return node ? node->left : NULL;
}

struct node *avl_right(struct node *node) {
  return node ? node->right : NULL;
}

int avl_height(struct node *node) {
  if (!node)
    return 0;
  
  int left_height, right_height;

  left_height = avl_height(node->left);
  right_height = avl_height(node->right);

  node->balance = right_height - left_height;

  return (left_height > right_height) ? left_height+1 : right_height+1;
}

int avl_balance(struct node *node) {
  return node ? node->balance : 0;
}

struct node *avl_fix_props(struct node *node) {
  if (!node)
    return NULL;

  node->left = avl_fix_props(node->left);
  node->right = avl_fix_props(node->right);
  
  if (node->balance <= 1 && node->balance >= -1)
    return node;

  if (node->balance == -2) {
    if (avl_balance(node->left) == -1)
      node = avl_rotate_right(node);
    else if (avl_balance(node->right) == 1)
      node = avl_rotate_leftright(node);
  } else if (node->balance == 2) {
    if (avl_balance(node->right) == 1)
      node = avl_rotate_left(node);
    else if (avl_balance(node->right) == -1)
      node = avl_rotate_rightleft(node);
  }

  avl_height(node);

  return node;
}

struct node *avl_rotate_left(struct node *node) {
	if (!node)
		return NULL;

	struct node *k1, *k2, *y;

	k2 = node;
	k1 = node->right;
	y = k1->left;

	k1->left = k2;
	k2->right = y;

	return k1;
}

struct node *avl_rotate_leftright(struct node *node) {
	if (!node)
		return NULL;

	node->left = avl_rotate_left(node->left);
	return avl_rotate_right(node);
}

struct node *avl_rotate_right(struct node *node) {
	if (!node)
		return NULL;

	struct node *k1, *k2, *y;

	k2 = node;
	k1 = node->left;
	y = k1->right;

	k1->right = k2;
	k2->left = y;

	return k1;
}

struct node *avl_rotate_rightleft(struct node *node) {
	if (!node)
		return NULL;

	node->right = avl_rotate_right(node->right);
	return avl_rotate_left(node);
}

struct node *bst_insert(struct node *node, int value) {
  if (!node)
    return avl_create_node(value);
  
  if (value < node->value)
    node->left = bst_insert(node->left, value);
  else if (value > node->value)
    node->right = bst_insert(node->right, value);
  
  return node;
}

void avl_inorder_print(struct node *root) {
  if (!root) return;

  avl_inorder_print(root->left);

  printf("%d, ", root->value);

  avl_inorder_print(root->right);
}

void avl_indented_print(struct node *root, int level) {
  if (!root) return;

  printf("%d\n", root->value);

  level++;

  if (root->left) {
    for (int i = 0; i < level; i++) printf("  ");
    avl_indented_print(root->left, level);
  }

  if (root->right) {
    for (int i = 0; i < level; i++) printf("  ");
    avl_indented_print(root->right, level);
  }
}