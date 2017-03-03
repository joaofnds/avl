struct node {
  int value;
  int balance;
  struct node *left, *right;
};

struct node *avl_create_node(int value);

void avl_destroy(struct node *root);

struct node *avl_insert(struct node *node, int value);

struct node *avl_remove(struct node *node, int value);

struct node *avl_find(struct node *node, int value);

struct node *avl_min(struct node *node);

struct node *avl_max(struct node *node);

struct node *avl_left(struct node *node);

struct node *avl_right(struct node *node);

int avl_height(struct node *node);

int avl_balance(struct node *node);

struct node *avl_fix_props(struct node *node);

struct node *avl_rotate_left(struct node *node);

struct node *avl_rotate_leftright(struct node *node);

struct node *avl_rotate_right(struct node *node);

struct node *avl_rotate_rightleft(struct node *node);

struct node *bst_insert(struct node *node, int value);

void avl_inorder_print(struct node *root);

void avl_indented_print(struct node *root, int level);

struct node *bst_remove(struct node *node, int value);