#include "Form.hpp"

//primeiro construtor padrão não recebe argumentos e inicializa 
//os valores padrão para o nome, notas de assinatura e execução, e define isSigned como falso.
Form::Form(void) : name(CYAN "default_form" RESET), signGrade(1), execGrade(1)
{
	this->isSigned = false;
}
//segundo construtor é uma cópia que inicializa um novo objeto Form 
//com base em um objeto existente
Form::Form(const Form& copy) : name(copy.name), signGrade(copy.signGrade), \
	execGrade(copy.signGrade)
{
	this->isSigned = copy.isSigned;
}
//construtor personalizado que recebe um nome, notas de assinatura e execução como 
//argumentos e inicializa os valores correspondentes. Ele também verifica se as notas 
//estão dentro dos limites (MAX_GRADE e MIN_GRADE) e lança exceções personalizadas se 
//estiverem fora dos limites
Form::Form(const std::string& name, int signGrade, int execGrade) : name(name), \
	signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < Form::MAX_GRADE || execGrade < Form::MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > Form::MIN_GRADE || execGrade > Form::MIN_GRADE)
		throw Form::GradeTooLowException();
	this->isSigned = false;
	std::cout << this->name << GREEN << "Form was created."<< RESET << std::endl;
}
//destrutor padrão
Form::~Form(void)
{
	
}
//sobrecarrega o operador de atribuição (=) 
//para permitir a cópia de objetos Form. Ele verifica se o objeto 
//não está sendo atribuído a si mesmo antes de realizar a cópia
Form& Form::operator=(const Form& right)
{
	if (this == &right)
		return (*this);
	this->isSigned = right.isSigned;
	return (*this);
}

//recebe um objeto Bureaucrat como argumento e verifica 
//se a nota do burocrata é alta o suficiente para assinar o 
//formulário. Se a nota do burocrata for muito baixa, ele lança a exceção GradeTooLowException
void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}
//métodos getters para cada atributo
std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::hasBeenSigned(void) const
{
	return (this->isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecutionGrade(void) const
{
	return (this->execGrade);
}

//sobrecarrega o operador << para permitir a impressão de objetos Form
std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string sign = form.hasBeenSigned() ? " ✅ " : " ❌ ";
	
	out << BLUE "Form: " RESET + form.getName() + "\n";
	out << BLUE "\tSigned? " RESET + sign + "\n";
	out << BLUE "\n Signing Grade: " RESET << form.getSignGrade() << "\n";
	out << BLUE "\tExecution Grade: " RESET << form.getExecutionGrade() << "\n";
	out << std::endl;
	return (out);
}
//implementação das exceções personalizadas
const char *Form::GradeTooHighException::what() const throw()
{
	return (RED "\n\tForm Exception: grade is too high\n" RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (RED "\n\tForm Exception: grade is too low\n" RESET);
}