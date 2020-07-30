// Insertion of a new word and meaning into dictionary
struct dictionaryADT* insert(struct dictionaryADT *D, wordMeaning w);
// Returns the height of the supplied node in the tree
int heightOfNode(struct dictionaryADT *D);
// Updates the height of the supplied node
void updateHeight(struct dictionaryADT *D);
// Performes single left rotation on supplied node
struct dictionaryADT* singleRotateLeft(struct dictionaryADT *D);
// Performes single right rotation on supplied node
struct dictionaryADT* singleRotateRight(struct dictionaryADT *D);
// Performes double left rotation on supplied node
struct dictionaryADT* doubleRotateLeft(struct dictionaryADT *D);
// Performes double right rotation on supplied node
struct dictionaryADT* doubleRotateRight(struct dictionaryADT *D);
// Display the information about all the words and meanings (Hierarchically)
void display(struct dictionaryADT *D,int n);
// Searches for the word in the tree and print its meaning
void search(struct dictionaryADT *D, char word[]);