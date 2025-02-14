#pragma once

#include <vector>
#include <algorithm>

namespace batch_insert {

// Version naïve : insertion une par une
template<typename T>
void naive_batch_insert(std::vector<T>& vec, const std::vector<T>& values) {
    for (const auto& value : values) {
        auto it = std::lower_bound(vec.begin(), vec.end(), value);
        if (it == vec.end() || *it != value) {
            vec.insert(it, value);
        }
    }
}

// Version optimisée : une seule copie (optimisée)
template<typename T>
void optimized_batch_insert(std::vector<T>& vec, const std::vector<T>& values) {
    if (values.empty()) return;
    
    // Copier, trier et éliminer les doublons dans les nouvelles valeurs
    std::vector<T> new_vals = values;
    std::sort(new_vals.begin(), new_vals.end());
    new_vals.erase(std::unique(new_vals.begin(), new_vals.end()), new_vals.end());
    
    // Fusionner les deux vecteurs triés à l'aide de std::set_union
    std::vector<T> result;
    result.reserve(vec.size() + new_vals.size());
    std::set_union(vec.begin(), vec.end(), new_vals.begin(), new_vals.end(), std::back_inserter(result));
    
    // Remplacer le vecteur original par le résultat fusionné
    vec = std::move(result);
}

// Nouvelle version optimisée acceptant les valeurs par copie
template<typename T>
void optimized_batch_insert2(std::vector<T>& vec, std::vector<T> values) {
    if (values.empty()) return;
    
    // Trier et supprimer les doublons dans les nouvelles valeurs
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    
    // Se souvenir de la taille initiale
    const auto oldSize = vec.size();
    
    // Ajouter les nouvelles valeurs
    vec.insert(vec.end(),
               std::make_move_iterator(values.begin()),
               std::make_move_iterator(values.end()));
    
    // Fusionner les deux segments triés
    std::inplace_merge(vec.begin(), vec.begin() + oldSize, vec.end());
    
    // Supprimer d'éventuels doublons sur la frontière de fusion
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

} // namespace batch_insert 