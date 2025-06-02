/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2025/06/02 19:33:49 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <sstream>

#define T_INCREMENT 0
#define T_DECREMENT 1
#define MIN_GRADE 150
#define MAX_GRADE 1
#define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)

// void	error_init_constructor(void)
// {
// 	Bureaucrat *foo;

// 	std::cout << C << "Test: Error: Init constructor" << E << std::endl;
// 	try
// 	{
// 		foo = new Bureaucrat("dacortes", 151);
// 	}
// 	catch (const std::range_error &error)
// 	{
// 		std::cout << error.what() << std::endl;
// 	}
// 	try
// 	{
// 		foo = new Bureaucrat("dacortes", -1);
// 	}
// 	catch (const std::range_error &error)
// 	{
// 		std::cout << error.what() << std::endl;
// 	}
// 	std::cout << C << "Test: Init constructor" << E << std::endl;
// 	foo = new Bureaucrat("dacortes", 150);
// 	std::cout << *foo << std::endl;
// 	delete foo;
// }

// void	loop_error_grade_low(void)
// {
// 	Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test loop: Error: decrement" << E << std::endl;
//     int dec = 1;
//     try
//     {
//         while (true)
//         {
//             dec = foo.decrementGrade(1);
//             std::cout << B << "Decrement: " << E << dec << std::endl;
//             std::cout << foo << std::endl;
//         }
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// }

// void	error_grade_low(void)
// {
// 	Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test: Error: decrement" << E << std::endl;
// 	try
// 	{
//     	std::cout << B << "Test: Error: number negative" << E << std::endl;
// 		foo.decrementGrade(-1);
// 		std::cout << foo << std::endl;
// 	}
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// 	try
// 	{
// 		std::cout << B << "Test: Error: parameter larger than default"
// 			<< E << std::endl;
// 		foo.decrementGrade(200);
// 		std::cout << foo << std::endl;
// 	}
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// }

// void	loop_error_grade_high(void)
// {
// 	Bureaucrat foo("dacortes", 150);

//     std::cout << C << "Test loop: Error: increment" << E << std::endl;
//     int dec = 1;
//     try
//     {
//         while (true)
//         {
//             dec = foo.IncrementGrade(1);
//             std::cout << B << "Decrement: " << E << dec << std::endl;
//             std::cout << foo << std::endl;
//         }
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// }

// void	error_grade_high(void)
// {
// 	Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test: Error: increment" << E << std::endl;
// 	try
// 	{
//     	std::cout << B << "Test: Error: number negative" << E << std::endl;
// 		foo.IncrementGrade(-1);
// 		std::cout << foo << std::endl;
// 	}
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// 	try
// 	{
// 		std::cout << B << "Test: Error: parameter larger than default"
// 			<< std::endl;
// 		foo.IncrementGrade(200);
// 		std::cout << foo << std::endl;
// 	}
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// }

// void	loop_test_grade_high(void)
// {
// 	Bureaucrat foo("dacortes", 150);

//     std::cout << C << "Test loop: increment" << E << std::endl;
//     try
//     {
//         while (foo.getGrade() != 1)
//         {
//             foo.IncrementGrade(1);
//             std::cout << foo << std::endl;
//         }
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// }

// void	loop_test_grade_low(void)
// {

// 	Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test loop: decrement" << E << std::endl;
//     try
//     {
//         while (foo.getGrade() != 150)
//         {
//             foo.decrementGrade(1);
//             std::cout << foo << std::endl;
//         }
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
// }

// void    number_zero_test(void)
// {
//     Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test number zero: increment" << E << std::endl;
//     try
//     {
//         foo.IncrementGrade(0);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     std::cout << C << "Test number zero: decrement" << E << std::endl;
//     try
//     {
//         foo.decrementGrade(0);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     std::cout << foo << std::endl;
// }

// void number_negative_test(void)
// {
//     Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test number negative: increment" << E << std::endl;
//     try
//     {
//         foo.IncrementGrade(-2000);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     std::cout << C << "Test number negative: decrement" << E << std::endl;
//     try
//     {
//         foo.decrementGrade(-2000);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     std::cout << foo << std::endl;
// }

// void number_positive_range(void)
// {
//     Bureaucrat foo("dacortes", 1);

//     std::cout << C << "Test positive: increment" << E << std::endl;
//     try
//     {
//         foo.IncrementGrade(2000);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     try
//     {
//         foo.IncrementGrade(65385);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     try
//     {
//         foo.IncrementGrade(150);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     try
//     {
//         foo.IncrementGrade(1);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     try
//     {
//         foo.IncrementGrade(4);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     std::cout << C << "Test number negative: decrement" << E << std::endl;
//     try
//     {
//         foo.decrementGrade(2000);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     try
//     {
//         foo.decrementGrade(150);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     try
//     {
//         foo.decrementGrade(65385);
//         std::cout << foo << std::endl;
//     }
//     catch (const std::range_error &error)
//     {
//         std::cout << error.what() << std::endl;
//     }
//     std::cout << foo << std::endl;
// }

// int	main(void)
// {
// 	error_init_constructor();
// 	loop_error_grade_low();
// 	loop_error_grade_high();
// 	loop_test_grade_high();
// 	loop_test_grade_low();
// 	error_grade_low();
// 	error_grade_high();

//     number_zero_test();
//     number_negative_test();
//     number_positive_range();
// 	return (EXIT_SUCCESS);
// }

// test eralonso
Bureaucrat	testConstructorGrade( unsigned int grade, int& catched )
{
	Bureaucrat	Joan( "Juan", MIN_GRADE );

	catched = 0;
	try
	{
		Bureaucrat	Juan( "Juan", grade );
        // std::cout << R << "------>\n" << Juan << std::endl;
		return ( Juan );
	}
	catch ( std::exception& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
		catched = 1;
	}
	return ( Joan );
}

void	iterGrade( Bureaucrat& Juan, unsigned int n, unsigned int mode )
{
	for ( unsigned int i = 0; i < n; i++ )
	{
		if ( mode == T_DECREMENT )
		{
			std::cout << "\tDecrement grade by 1" << std::endl;
			Juan.decrementGrade();
		}
		else
		{
			std::cout << "\tIncrement grade by 1" << std::endl;
			Juan.incrementGrade();
		}
	}
}

void	testModifyGrade( unsigned int mode, unsigned int grade, unsigned int n )
{
	int			catched;
	Bureaucrat	Juan;

	catched = 0;
	Juan = testConstructorGrade( grade, catched );
	if ( catched == 1 )
		return ;
	std::cout << "\t[ START ]: Juan stats -> " << Juan << std::endl;
	try
	{
		iterGrade( Juan, n, mode );
	}
	catch ( std::exception& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
	std::cout << "\t[ END ]: Juan stats -> " << Juan << std::endl;
}

int	main( void )
{
	int	catched;

	//Constructor Tests
	
	//	Out of range Grades
	std::cout << "Test too low grade in constructor: Bureaucrat\tJuan( \"Juan\", 151 )"  << std::endl;
	testConstructorGrade( 151, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test too high grade in constructor: Bureaucrat\tJuan( \"Juan\", 0 )"  << std::endl;
	testConstructorGrade( 0, catched );
	std::cout << "End of test\n"  << std::endl;
	
	//	Valid Grades
	std::cout << "Test MAX_GRADE (" << MAX_GRADE << ") constructor: Bureaucrat\tJuan( \"Juan\", " << MAX_GRADE << " )"  << std::endl;
	testConstructorGrade( MAX_GRADE, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test MIN_GRADE (" << MIN_GRADE << ") constructor: Bureaucrat\tJuan( \"Juan\", " << MIN_GRADE << " )"  << std::endl;
	testConstructorGrade( MIN_GRADE, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test MID_GRADE " << MID_GRADE << " constructor: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testConstructorGrade( MID_GRADE, catched );
	std::cout << "End of test\n"  << std::endl;

	//Increment/Decrement Methods Tests
	
	//	Out of range Grades Iterations
	std::cout << "Test too low grade with decrement method: Bureaucrat\tJuan( \"Juan\", 150 )"  << std::endl;
	testModifyGrade( T_DECREMENT, 150, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test too high grade with increment method: Bureaucrat\tJuan( \"Juan\", 1 )"  << std::endl;
	testModifyGrade( T_INCREMENT, 1, 1 );
	std::cout << "End of test\n"  << std::endl;

	//	Valid Grades Iterations
	std::cout << "Test decrement method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( T_DECREMENT, MID_GRADE, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test increment method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( T_INCREMENT, MID_GRADE, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test decrement method, multiple iterations (10): Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( T_DECREMENT, MID_GRADE, 10 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test increment method, multiple iterations (10): Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	testModifyGrade( T_INCREMENT, MID_GRADE, 10 );
	std::cout << "End of test\n"  << std::endl;

	//Getter Methods Tests

	//	getName()
	Bureaucrat	Juan = testConstructorGrade( MID_GRADE, catched );
	std::cout << "Test getName method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	std::cout << "Name: " << Juan.getName() << std::endl;
	std::cout << "End of test\n"  << std::endl;

	//	getGrade()
	std::cout << "Test getGrade method: Bureaucrat\tJuan( \"Juan\", " << MID_GRADE << " )"  << std::endl;
	std::cout << "Grade: " << Juan.getGrade() << std::endl;
	std::cout << "End of test\n"  << std::endl;

	return ( 0 );
}
