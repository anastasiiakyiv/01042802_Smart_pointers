/*
Спробуйте реалізувати ще один клас C++, але з використання розумних
вказівників! Перед вами покладено завдання виконати замовлення на товар у
кошику. Ваші класи мають бути названі ShopItem і ShopOrder. У ShopItem
мають бути: ідентифікатор, назва виробу, його ціна.
У товарному замовленні (ShopOrder) зберігається така інформація:
назва виробу, ціна одиниці товару, кількість замовлених товарів.
У класі ShopItem мають бути методи доступу, які дозволять
отримати та встановити всю вищезазначену інформацію.
У ShopOrder має бути метод, щоб отримати загальну вартість за замовлення;
виводити на екран замовлення зручним для користувача способом.
Об’єкти класу ShopItem можуть бути записані у масиві. Ви маєте скористатися
підходом до створення замовлення і розрахунку загальної вартості, який
використовує звертання до об’єктів і виклику методів через розумні вказівники.
*/

#include <iostream>
#include <vector>
#include <memory>

class ShopItem {
private:
	int identifier;
	std::string itemName;
	double itemPrice;

public:
	ShopItem(int ID, std::string name, double price) :
		identifier(ID), itemName(name), itemPrice(price) {}

	int getIdentifier() const {
		return identifier;
	}

	std::string getItemName() const {
		return itemName;
	}

	double getItemPrice() const {
		return itemPrice;
	}

	void setIdentifier(const int& newIdentifier) {
		identifier = newIdentifier;
	}

	void setItemName(const std::string& newItemName) {
		itemName = newItemName;
	}

	void setItemPrice(const double& newItemPrice) {
		itemPrice = newItemPrice;
	}
};

class ShopOrder {
private:
	std::vector<std::shared_ptr<ShopItem>> items;
	std::vector<int> quantities;

public:
	void addItem(std::shared_ptr<ShopItem> item, int quantity) {
		items.push_back(item);
		quantities.push_back(quantity);
	}

	double getOrderPrice() const {
		double orderPrice = 0.0;
		for (int i = 0; i < items.size(); ++i) {
			orderPrice += items[i]->getItemPrice() * quantities[i];
		}
		return orderPrice;
	}

	void showOrder() const {
		std::cout << "Please check the order details: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < items.size(); ++i) {
			std::cout << items[i]->getItemName() << ", quantity: " << quantities[i] << std::endl;
			std::cout << "Price per unit: " << items[i]->getItemPrice() << " UAH" << std::endl;
			std::cout << std::endl;
		}
		std::cout << "Total amount: " << getOrderPrice() << " UAH" << std::endl;
	}
};

int main() {
	std::shared_ptr<ShopItem> item1(new ShopItem(443747, "Dining table Oliver", 12999));
	std::shared_ptr<ShopItem> item2(new ShopItem(858449, "Chair Oliver", 1864.00));
	std::shared_ptr<ShopItem> item3(new ShopItem(152935, "Wardrobe Gelar", 8248.00));
	std::shared_ptr<ShopItem> item4(new ShopItem(989751, "Corner sofa F106", 86400.00));

	ShopOrder order;

	order.addItem(item1, 1);
	order.addItem(item2, 4);
	order.addItem(item3, 1);
	order.addItem(item4, 1);

	order.showOrder();

	return 0;
}