// #include "party.hpp"
// #include <algorithm>

// Shop::Shop()
// {
//     TowersToBuy["Wood"] = Tower{0, 10, 5, 1.0f, 50, Tower_Type::Wood};
//     TowersToBuy["Rock"] = Tower{1, 20, 7, 2.0f, 75, Tower_Type::Rock};
// }

// void Shop::displayItems() const
// {
//     std::cout << "Tours en vente : " << std::endl;
//     for (const auto& pair : TowersToBuy)
//     {
//         const auto& tower = pair.second;
//         std::cout << "Nom : " << pair.first 
//                   << ", Type : " << static_cast<int>(tower.type) 
//                   << ", Puissance : " << tower.fire_power 
//                   << ", Distance : " << tower.fire_distance 
//                   << ", Rythme : " << tower.fire_rythm 
//                   << ", Prix : " << tower.price 
//                   << std::endl;
//     }
// }

// void Shop::buyItems(Player& player)
// {
//     displayItems();

//     int itemName;
//     std::cout << "Entrez le nom de la tour désirée : " << std::endl;
//     std::cin.ignore();
//     std::getline(std::cin, itemName);

//     auto it = TowersToBuy.find(itemName);
//     if (it == TowersToBuy.end())
//     {
//         std::cout << "Tour non trouvée." << std::endl;
//         return;
//     }

//     Tower& selectedTower = it -> second;

//     if (player.buy(selectedTower.price))
//     {
//         player.addTower(selectedTower);
//         std::cout << "Achat terminé. Vous avez acheté : " << itemName << std::endl;
//     }
// }
