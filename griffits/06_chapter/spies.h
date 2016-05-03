typedef struct node {
  char * question;
  struct node * yes;
  struct node * no;
} node;

int yes_no (char * question);
node * create(char * question);
void release(node * n);
