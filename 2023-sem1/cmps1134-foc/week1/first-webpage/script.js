// Get the header element
const header = document.querySelector('header');

// Apply styles for a metallic and shiny effect
header.style.backgroundColor = '#D3D3D3'; // Silver color
header.style.color = '#333';
header.style.padding = '1.5rem';
header.style.textAlign = 'center';
header.style.fontWeight = 'bold';
header.style.fontSize = '2.5rem';
header.style.borderBottom = '6px solid #B0C4DE'; // Slightly darker shade of silver

// Add event listener for mouseover effect (optional)
header.addEventListener('mouseover', () => {
    header.style.backgroundColor = '#C0C0C0'; // Lighter shade of silver on hover
});

// Add event listener for mouseout effect (optional)
header.addEventListener('mouseout', () => {
    header.style.backgroundColor = '#D3D3D3'; // Restore original color on mouseout
});
