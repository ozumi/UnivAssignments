class Polynomial;

class Term{
	friend class Polynomial;
private:
	float coef; // coefficient
	int exp;    // exponent
};

class Polynomial
{
public:
	// Default constructor p(x) = 0
	Polynomial() {
		capacity = 10;
		terms = 0;
		termArray = new Term[capacity];
	};

	// Copy constructor
	Polynomial(const Polynomial& source);

	// Destructor
	~Polynomial();

	// Assignment operator
	Polynomial& operator = (const Polynomial& source);

	// Sum of *this and source polynomials
	Polynomial Add(const Polynomial& source);

	// Product of *this and source polynomials
	Polynomial Mult(const Polynomial& source);

	// Evaluate polynomial *this at x and return the result
	float Eval(float x);

	// Print polynomial
	void Print();

	// Add new term
	void NewTerm(const float coef, const int exp);
	
	// Functions to access private data
	int Capacity() const { return capacity; }
	int Terms() const { return terms; }
	Term& GetTerm(int x) const { return termArray[x]; }
	
private:
	// Data
	Term *termArray;
	int capacity;
	int terms;
};
