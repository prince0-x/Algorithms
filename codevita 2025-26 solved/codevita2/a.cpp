#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// --- Helper Functions ---

string repeat(char c, int n) {
    if (n <= 0) return "";
    return string(n, c);
}

// Pads a string with spaces to the right until it reaches width L
string pad_line(string s, int L) {
    if ((int)s.length() >= L) return s;
    return s + repeat(' ', L - s.length());
}

// --- Component Generators ---

// Generates a Roof
// inverted = false: ^ shape (for H, L, R)
// inverted = true:  v shape (for U, D)
// mirrored = false: / \ (for H, U)
// mirrored = true:  \ / (for L, R, D)
vector<string> get_roof(int L, bool inverted, bool mirrored) {
    vector<string> rows;
    int r_height = (L + 1) / 2;
    
    // Determine Slash Characters
    char left_slash, right_slash;
    
    if (!inverted) {
        // Pointing Up
        left_slash = mirrored ? '\\' : '/';
        right_slash = mirrored ? '/' : '\\';
        
        // If L is odd, top is ^
        if (L % 2 != 0) {
            string line = repeat(' ', r_height - 1) + "^";
            rows.push_back(pad_line(line, L));
        }
        
        int start = (L % 2 != 0) ? 1 : 0;
        for(int i = start; i < r_height; ++i) {
            int outer = r_height - 1 - i;
            int inner = L - 2 - (2 * outer);
            string line = repeat(' ', outer) + left_slash + repeat(' ', inner) + right_slash;
            rows.push_back(pad_line(line, L));
        }
    } else {
        // Pointing Down (Inverted)
        // For inverted H (U): Left is \, Right is /
        // For inverted L (D): Left is /, Right is \
        left_slash = mirrored ? '/' : '\\';
        right_slash = mirrored ? '\\' : '/';
        
        // Generate body from Wide to Narrow
        int start = (L % 2 != 0) ? 1 : 0;
        for(int i = r_height - 1; i >= start; --i) {
            int outer = r_height - 1 - i;
            int inner = L - 2 - (2 * outer);
            string line = repeat(' ', outer) + left_slash + repeat(' ', inner) + right_slash;
            rows.push_back(pad_line(line, L));
        }
        
        // If L is odd, bottom is v (or just the tip)
        if (L % 2 != 0) {
            // Usually 'v' is the inverse of '^'
            string line = repeat(' ', r_height - 1) + "v"; 
            rows.push_back(pad_line(line, L));
        }
    }
    return rows;
}

// --- Main House Logic ---

struct House {
    vector<string> lines;
    int width;
    int height;
};

House generate_house(string spec) {
    // Parse Spec
    size_t x1 = spec.find('x');
    size_t x2 = spec.find('x', x1 + 1);
    int L = stoi(spec.substr(0, x1));
    int H = stoi(spec.substr(x1 + 1, x2 - x1 - 1));
    char D = spec.back();
    
    House h;
    h.width = L;
    
    // Configuration
    bool inverted = (D == 'U' || D == 'D');
    // Walls are swapped for L, R, and D
    bool walls_swapped = (D == 'L' || D == 'R' || D == 'D');
    // Roof is mirrored for L, R
    // For D (inverted L), we handle logic inside get_roof relative to U
    bool roof_mirrored = (D == 'L' || D == 'R'); 
    // Special case for D: It is inverted L.
    // U is Inverted H. H has / \. U has \ /.
    // L has \ /. D (Inverted L) has / \.
    // So D is "mirrored" relative to U logic.
    if (D == 'D') roof_mirrored = true; 

    // 1. Generate Parts
    vector<string> roof = get_roof(L, inverted, roof_mirrored);
    vector<string> walls;
    string base = repeat('#', L);
    
    char w_left = walls_swapped ? '&' : '@';
    char w_right = walls_swapped ? '@' : '&';
    
    for(int i=0; i<H; ++i) {
        string line = "";
        line += w_left;
        if (L > 2) line += repeat(' ', L - 2);
        line += w_right;
        walls.push_back(pad_line(line, L));
    }
    
    // 2. Assemble
    if (!inverted) {
        // Standard: Roof -> Walls -> Base
        h.lines.insert(h.lines.end(), roof.begin(), roof.end());
        h.lines.insert(h.lines.end(), walls.begin(), walls.end());
        h.lines.push_back(base);
    } else {
        // Inverted: Base -> Walls -> Roof
        h.lines.push_back(base);
        h.lines.insert(h.lines.end(), walls.begin(), walls.end());
        h.lines.insert(h.lines.end(), roof.begin(), roof.end());
    }
    
    h.height = h.lines.size();
    return h;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line_in;
    if (!getline(cin, line_in)) return 0;
    
    stringstream ss(line_in);
    string spec;
    vector<House> houses;
    int max_total_h = 0;
    
    // 1. Parse and Generate all houses
    while(ss >> spec) {
        House h = generate_house(spec);
        houses.push_back(h);
        if (h.height > max_total_h) max_total_h = h.height;
    }
    
    if (houses.empty()) return 0;
    
    // 2. Align and Print
    // Alignment Rule: BOTTOM ALIGNMENT.
    // All houses sit on the ground (last row).
    // Shorter houses need padding at the TOP.
    
    for(int i = 0; i < max_total_h; ++i) {
        for(size_t j = 0; j < houses.size(); ++j) {
            House& h = houses[j];
            int padding_needed = max_total_h - h.height;
            
            if (i < padding_needed) {
                // Print empty space for this house width
                cout << repeat(' ', h.width);
            } else {
                // Print the actual house line
                cout << h.lines[i - padding_needed];
            }
            // NOTE: No space separator between houses based on visual evidence (Fig 3)
        }
        cout << "\n";
    }

    return 0;
}