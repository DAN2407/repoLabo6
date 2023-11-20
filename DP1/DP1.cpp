#include <iostream>
using namespace std;

struct Vitamin {
    int fill;
    int boost;
};

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int testCase = 0; testCase < numTestCases; ++testCase) {
        int numVitamins;
        cin >> numVitamins;

        Vitamin vitamins[100];  // Supongamos que hay un máximo de 100 vitaminas por prueba.

        for (int i = 0; i < numVitamins; ++i) {
            cin >> vitamins[i].fill >> vitamins[i].boost;
        }

        int gaugeLimit;
        cin >> gaugeLimit;

        int maxBoost = 0;
        int currentBoost = 0;

        for (int i = 0; i < numVitamins; ++i) {
            // Verifica si agregar esta vitamina excede el límite de la barra.
            if (currentBoost + vitamins[i].fill <= gaugeLimit) {
                currentBoost += vitamins[i].boost;
                maxBoost = max(maxBoost, currentBoost);
            } else {
                // Si agregar la vitamina excede el límite, reinicia la suma actual.
                currentBoost = 0;
            }
        }

        cout << "Max Boost for Test Case " << testCase + 1 << ": " << maxBoost << endl;
    }

    return 0;
}
