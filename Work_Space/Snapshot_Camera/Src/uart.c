#include "uart.h"


#define GPIOAEN		(1U<<0)
#define USART2EN	(1U<<17)

#define	CR1_TE		(1U<<3)
#define CR1_RE		(1U<<2)
#define CR1_UE		(1U<<13)
#define SR_TXE		(1U<<7)
#define SR_RXNE		(1U<<5)

#define SYS_FREQ	16000000
#define APB1_CLK	SYS_FREQ

#define UART_BAUDRATE		115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);


//void uart2_write(int ch);

int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void usart2_tx_init(void)
{
	/*******Configure uart GPIO pin*******/
	/*Enable clock access to gpioa*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/*Set PA2 alternate function type to UART_TX (AF7)*/
	GPIOA->AFR[0] &= ~(0xF<<8);
	GPIOA->AFR[0] |= (7U<<8);

	/*******Configure uart module*******/
	/*Enable clock access to uart2*/
	RCC->APB1ENR |= USART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART2->CR1 = CR1_TE; //Set to CR1_TE on purpose. Basically Setting everything else to zero
						  //is good for standard UART configuration.

	/*Enable uart module*/
	USART2->CR1 |= CR1_UE;//Now just add 1 to UE bit otherwise mess with previous settings

}

void usart2_rxtx_init(void)
{
	/*******Configure uart GPIO pin*******/
	/*Enable clock access to gpioa*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/*Set PA2 alternate function type to UART_TX (AF7)*/
	GPIOA->AFR[0] &= ~(0xF<<8);
	GPIOA->AFR[0] |= (7U<<8);

	/*Set PA3 mode to alternate function mode*/
	GPIOA->MODER &= ~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	/*Set PA3 alternate function type to UART_RX (AF7)*/
	GPIOA->AFR[0] &= ~(0xF<<12);
	GPIOA->AFR[0] |= (7U<<12);

	/*******Configure uart module*******/
	/*Enable clock access to uart2*/
	RCC->APB1ENR |= USART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART2->CR1 = (CR1_TE | CR1_RE); //Set to CR1_TE on purpose. Basically Setting everything else to zero
						  //is good for standard UART configuration. Enable transmitter and receiver

	/*Enable uart module*/
	USART2->CR1 |= CR1_UE;//Now just add 1 to UE bit otherwise mess with previous settings

}

char uart2_read(void)
{
	/*Make sure the receive data register is not empty. While its empty stay in while*/
	/*The data register is waiting on data*/
	while(!(USART2->SR & SR_RXNE)){}

	/*Read data*/
	return USART2->DR;
}

void uart2_write(int ch)
{
	/*Make sure the transmit data register is empty. While its not empty stay in while*/
	/*The data register still has data in it that it needs to send*/
	while(!(USART2->SR & SR_TXE)){}

	/*Write to transmit data register*/
	USART2->DR = (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, Baudrate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate)
{
	return ((PeriphClk + (Baudrate/2U))/Baudrate);
}
