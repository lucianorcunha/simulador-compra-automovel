#include <iostream>
#include <clocale>
#include <iomanip>
#include <sstream>
#include <stdio.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "pt_BR.utf8");

	const double IPI = 0.08;
	const double DESCONTO = 0.035;

	int carro, escolhaOpcional, continuarOpcional, repetir;
	int contador0 = 0, contador1 = 0, contador2 = 0, contador3 = 0, contador4 =	0;
	int conta_carro1 = 0, conta_carro2 = 0, conta_carro3 = 0, conta_carro4 = 0, conta_carro5 = 0;
	bool opcional1 = false, opcional2 = false, opcional3 = false;
	bool opcional0 = false, opcional4 = false;
	double valorCarro = 0, valorCarroIPI = 0, valorCarroTotal = 0;

	do {
		cout << "-------- Bem vindo a Volkswagen ------- \n";
		cout << "   Escolha um automóvel para iniciar: \n";
		cout << "--------------------------------------- \n";
		cout << "1) Gol - 1.0 MPI         - R$ 40.690,00 \n";
		cout << "2) Polo - 1.0            - R$ 46.990,00 \n";
		cout << "3) Fox - Connect 1.6     - R$ 48.490,00 \n";
		cout << "4) Up! - Connect 170 TSI - R$ 51.890,00 \n";
		cout << "5) Voyage - 1.6          - R$ 52.790,00 \n";
		cout << "--------------------------------------- \n\n";

		do {
			cout << "Digite uma opção de 1 a 5: ";
			cin >> carro;
			if (carro != 1 && 2 && 3 && 4 && 5)
			{
				cin.clear();
				cin.ignore();
			}
		} while (carro <= 0 || carro >= 6);

		switch (carro) {
		case 1:
			valorCarro = 4069000;
			conta_carro1 += 1;
			break;
		case 2:
			valorCarro = 4699000;
			conta_carro2 += 1;
			break;
		case 3:
			valorCarro = 4849000;
			conta_carro3 += 1;
			break;
		case 4:
			valorCarro = 5189000;
			conta_carro4 += 1;
			break;
		case 5:
			valorCarro = 5279000;
			conta_carro5 += 1;
			break;
		}

		valorCarroIPI = (valorCarro * IPI) + valorCarro;
		float opc1 = (valorCarro * 0.02);
		float opc2 = (valorCarroIPI * 0.02);
		float opc3 = (valorCarroIPI * 0.02);
		float opcCompleto = (opc1 + opc2 + opc3);

			cout << "\n-------------- Escolha os opcionais! -------------\n";
			cout << "          (COMPLETO -> Promoção de 3,5%)\n";
			cout << "--------------------------------------------------\n";
			cout << "0) Nenhum opcional (Super básico)\n";
			cout << "1) Trio elétrico (Alarme, vidro e tranca elétrica)\n";
			cout << "2) Ar condicionado\n";
			cout << "3) Direção hidráulica\n";
			cout << "4) Completo (Trio elétrico, ar e direção)\n";
			cout << "--------------------------------------------------\n";

		do {

			do {
				cout << "\nEscolha um opcional: ";
				cin >> escolhaOpcional;
				if (escolhaOpcional < 0 && escolhaOpcional > 4)
					{
						cin.clear();
						cin.ignore();
					}
			} while (escolhaOpcional < 0 || escolhaOpcional > 4);

			switch (escolhaOpcional) {

			case 0:
				cout << "\nVocê escolheu: SEM OPCIONAIS.\n";
				opcional0 = true;
				break;
			case 1:
				cout << "\nVocê escolheu: TRIO ELÉTRICO.\n";
				if (opcional1) {
					cout << "Essa opção já foi selecionada anteriormente, escolha outra!\n";
				} else {
					opcional1 = true;
					do {
						cout << "Escolher outro opcional? (1) SIM / (2) NÃO: ";
						cin >> continuarOpcional;
						if (continuarOpcional != 1 && 2)
							{
								cin.clear();
								cin.ignore();
							}
					} while (continuarOpcional < 1 || continuarOpcional > 2);
				}
				break;
			case 2:
				cout << "\nVocê escolheu: AR CONDICIONADO.\n";
				if (opcional2) {
					cout << "Essa opção já foi selecionada anteriormente, escolha outra!\n";
				} else {
					opcional2 = true;
					do {
						cout << "Escolher outro opcional? (1) SIM / (2) NÃO: ";
						cin >> continuarOpcional;
						if (continuarOpcional != 1 && 2)
							{
								cin.clear();
								cin.ignore();
							}
					} while (continuarOpcional < 1 || continuarOpcional > 2);
				}
				break;
			case 3:
				cout << "\nVocê escolheu: DIREÇÃO HIDRÁULICA.\n";
				if (opcional3) {
					cout << "Essa opção já foi selecionada anteriormente, escolha outra!\n";
				} else {
					opcional3 = true;
					do {
						cout << "Escolher outro opcional? (1) SIM / (2) NÃO: ";
						cin >> continuarOpcional;
						if (continuarOpcional != 1 && 2)
							{
								cin.clear();
								cin.ignore();
							}
					} while (continuarOpcional < 1 || continuarOpcional > 2);
				}
				break;
			case 4:
				cout << "\nVocê escolheu: COMPLETO.\n";
				opcional4 = true;
				break;
			}

		} while (continuarOpcional != 2 && (escolhaOpcional != 0 && escolhaOpcional != 4
				&& (!opcional1 || !opcional2 || !opcional3)));

		if (opcional0 == true)
		{
			opcional1 = false; opcional2 = false; opcional3 = false;
			valorCarroTotal = valorCarroIPI;
			contador0 += 1;
		}

		else if (opcional4 == true)
		{
			opcional1 = false; opcional2 = false; opcional3 = false;
			valorCarroTotal = valorCarroIPI + opcCompleto;
			valorCarroTotal = valorCarroTotal - (valorCarroTotal * DESCONTO);
			contador4 += 1;
		}

		else if (opcional1 == true && opcional2 == false && opcional3 == false)
		{
			valorCarroTotal = valorCarroIPI + opc1;
			contador1 += 1;
		}

		else if (opcional1 == false && opcional2 == true && opcional3 == false)
		{
			valorCarroTotal = valorCarroIPI + opc2;
			contador2 += 1;
		}

		else if (opcional1 == false && opcional2 == false && opcional3 == true)
		{
			valorCarroTotal = valorCarroIPI + opc3;
			contador3 += 1;
		}

		else if (opcional1 == true && opcional2 == true && opcional3 == false)
		{
			valorCarroTotal = valorCarroIPI + opc1 + opc2;
			contador1 += 1;
			contador2 += 1;
		}

		else if (opcional1 == false && opcional2 == true && opcional3 == true)
		{
			valorCarroTotal = valorCarroIPI + opc2 + opc3;
			contador2 += 1;
			contador3 += 1;
		}

		else if (opcional1 == true && opcional2 == false && opcional3 == true)
		{
			valorCarroTotal = valorCarroIPI + opc1 + opc3;
			contador1 += 1;
			contador3 += 1;
		}

		else if (opcional1 == true && opcional2 == true && opcional3 == true)
		{
			valorCarroTotal = valorCarroIPI + opcCompleto;
			valorCarroTotal = valorCarroTotal - (valorCarroTotal * DESCONTO);
			contador4 += 1;

			cout << "\nVocê escolheu 3 opcionais = COMPLETO.\n";
		}

		else
		{
			break;
		}

		if (opcional1 || opcional2 || opcional3 || opcional0 || opcional4)
		{
		cout << "\nValor do automóvel a preço de fábrica: ";

		std::stringstream ss;
		ss.imbue(std::locale(""));
		ss << std::showbase << std::put_money(valorCarroTotal);
		std::cout << ss.str() << '\n';
		}

			do {
				cout << "\nREPETIR SIMULAÇÃO? (1) SIM / (2) NÃO: ";
				cin >> repetir;
				if (repetir != 1 && 2)
					{
						cin.clear();
						cin.ignore();
					}
			} while (repetir < 1 || repetir > 2);

		opcional1 = false;
		opcional2 = false;
		opcional3 = false;
		opcional0 = false;
		opcional4 = false;
		escolhaOpcional = 0;
		cout << "\n";

	} while (repetir == 1);

	cout << "\n-[Contador de automóveis]-";
	cout << "\nGol: " << conta_carro1;
	cout << "\nPolo: " << conta_carro2;
	cout << "\nFox: " << conta_carro3;
	cout << "\nUp!: " << conta_carro4;
	cout << "\nVoyage: " << conta_carro5;

	cout << "\n\n-[Contador de opcionais]-";
	cout << "\nSem opcionais (super básico): " << contador0;
	cout << "\nOpcional 1 (Trio elétrico): " << contador1;
	cout << "\nOpcional 2 (Ar condicionado): " << contador2;
	cout << "\nOpcional 3 (Direção hidráulica): " << contador3;
	cout << "\nOpcional 4 (Completo com desconto): " << contador4;

	return 0;
}



