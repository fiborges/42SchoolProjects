#include "AForm.hpp"

//primeiro construtor padrão não recebe argumentos e inicializa 
//os valores padrão para o nome, notas de assinatura e execução, e define isSigned como falso.
AForm::AForm(void) : name(CYAN "default_form" RESET), signGrade(1), execGrade(1)
{
	this->isSigned = false;
}
//segundo construtor é uma cópia que inicializa um novo objeto Form 
//com base em um objeto existente
AForm::AForm(const AForm& copy) : name(copy.name), signGrade(copy.signGrade), \
	execGrade(copy.signGrade)
{
	this->isSigned = copy.isSigned;
}
//construtor personalizado que recebe um nome, notas de assinatura e execução como 
//argumentos e inicializa os valores correspondentes. Ele também verifica se as notas 
//estão dentro dos limites (MAX_GRADE e MIN_GRADE) e lança exceções personalizadas se 
//estiverem fora dos limites
AForm::AForm(const std::string& name, int signGrade, int execGrade) : name(name), \
	signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < AForm::MAX_GRADE || execGrade < AForm::MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (signGrade > AForm::MIN_GRADE || execGrade > AForm::MIN_GRADE)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
	std::cout << this->name << GREEN << "Form was created."<< RESET << std::endl;
}
//destrutor padrão
AForm::~AForm(void)
{
	
}
//sobrecarrega o operador de atribuição (=) 
//para permitir a cópia de objetos Form. Ele verifica se o objeto 
//não está sendo atribuído a si mesmo antes de realizar a cópia
AForm& AForm::operator=(const AForm& right)
{
	if (this == &right)
		return (*this);
	this->isSigned = right.isSigned;
	return (*this);
}

//recebe um objeto Bureaucrat como argumento e verifica 
//se a nota do burocrata é alta o suficiente para assinar o 
//formulário. Se a nota do burocrata for muito baixa, ele lança a exceção GradeTooLowException
void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}
void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->hasBeenSigned())
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getExecutionGrade())
		throw AForm::BureaucratGradeTooLow();
	
	std::cout << executor.getName() << " executed " << this->name << std::endl;
	this->execute();
}
//métodos getters para cada atributo
std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::hasBeenSigned(void) const
{
	return (this->isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int AForm::getExecutionGrade(void) const
{
	return (this->execGrade);
}

void AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;	
}

//sobrecarrega o operador << para permitir a impressão de objetos Form
std::ostream& operator<<(std::ostream& out, const AForm& form)
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
const char *AForm::GradeTooHighException::what() const throw()
{
	return (RED "\n\tForm Exception: grade is too high\n" RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (RED "\n\tForm Exception: grade is too low\n" RESET);
}

const char *AForm::UnsignedFormException::what() const throw()
{
	return (RED "\n\tForm Exception: this form wasn't signed so it can't be executed.\n" RESET);
}

const char *AForm::BureaucratGradeTooLow::what() const throw()
{
	return (RED "\n\tForm Exception: unsufficient grade to execute.\n" RESET);
}