
#include "Bureaucrat.hpp"

//construtor padrao inicia por default com grade 150
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	
}
//construtor de copia atribuindo os valores do burocrata original (copy) para o burocrata atual (*this).
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}
//Este é um construtor personalizado que permite criar um burocrata com 
//um nome e uma nota especificos. verifica se a nota está dentro dos limites 
//aceitáveis (entre MAX_GRADE e MIN_GRADE) e lança exceções, caso contrário.
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
//destrutor
Bureaucrat::~Bureaucrat()
{
	
}
//retorna o nome do burocrata
std::string Bureaucrat::getName(void) const
{
	return (this->name);
}
// retorna a nota do burocrata.
int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

//aumenta a nota do burocrata em uma unidade, desde que a nota não ultrapasse o limite superior (MAX_GRADE).
// Caso contrário, lança a exceção GradeTooHighException.
void Bureaucrat::incrementGrade(void)
{
	LOG(GREEN "\nIncrementing grade..." RESET);
	if (this->grade - 1 < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}
//diminui a nota do burocrata em uma unidade, desde que a nota não caia abaixo do limite inferior (MIN_GRADE).
void Bureaucrat::decrementGrade(void)
{	
	LOG(RED "\nDecrementing grade..." RESET);
	if (this->grade + 1 > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}
//verifica se o grau do burocrata é suficientemente alto para assinar o formulário e, 
//em seguida, imprime mensagens apropriadas com base na situação.
void Bureaucrat::signForm(Form& form)
{
	if (this->grade <= form.getExecutionGrade())
		std::cout << this->name + " signed " + form.getName() << std::endl;
	else
		std::cout << this->name + " couldn't sign " + form.getName() \
			+ "(" << form.getSignGrade() << ") because their grade(" \
			<< this->grade << ") was too low" << std::endl;	
	form.beSigned(*this);
}
//permite que você atribua o valor de um burocrata a outro usando o operador =. 
//evita a autoatribuição (this == &otherCopy) e, em seguida, copia a nota do burocrata 
//otherCopy para o burocrata atual.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& otherCopy)
{
	if (this == &otherCopy)
		return (*this);
	this->grade = otherCopy.grade;
	return (*this);
}
//sobrecarrega o operador de inserção << para que eu possa imprimir objetos da classe Bureaucrat 
//de forma personalizada. formata a saída com o nome e a nota do burocrata.
std::ostream& operator<<(std::ostream& output, const Bureaucrat& fixedNumber)
{
	output << "\n" << fixedNumber.getName() << ", bureaucrat grade ";
	output << fixedNumber.getGrade() << "." << std::endl;
	return (output);
}

//sobrescreve a função what() da classe base std::exception para fornecer uma mensagem 
//de erro específica para exceções
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\n\tThe grade is too high.\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\n\tThe grade is too low.\n");
}