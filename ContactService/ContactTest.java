package ContactService;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactTest {

    @Test
    void testCreateValidContact() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertNotNull(contact);
    }

    // id //
    @Test
    void testCreateContactWithNullID() {
        assertThrows(IllegalArgumentException.class, () -> new Contact(null, "John", "Doe", "1234567890", "123 Main St"));
    }

    @Test
    void testCreateContactWithEmptyID() {
        assertThrows(IllegalArgumentException.class, () -> new Contact("", "John", "Doe", "1234567890", "123 Main St"));
    }

    @Test
    void testCreateContactWithLongID() {
        assertThrows(IllegalArgumentException.class, () -> new Contact("12345678901", "John", "Doe", "1234567890", "123 Main St"));
    }

    // first name //
    @Test
    void testSetFirstNameValid() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        contact.setFirstName("Jane");
        assertEquals("Jane", contact.getFirstName());
    }

    @Test
    void testSetFirstNameNull() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setFirstName(null));
    }
    
    @Test
    void testSetFirstNameEmpty() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setFirstName(""));
    }
    
    @Test
    void testSetFirstNameLong() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setFirstName("ThisFirstNameIsTooLong"));
    }

    // last name //
    @Test
    void testSetLastNameValid() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        contact.setLastName("Smith");
        assertEquals("Smith", contact.getLastName());
    }

    @Test
    void testSetLastNameNull() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setLastName(null));
    }
    
    @Test
    void testSetLastNameEmpty() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setLastName(""));
    }
    
    @Test
    void testSetLastNameLong() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setLastName("ThisLastNameIsTooLong"));
    }

    // phone //
    @Test
    void testSetPhoneValid() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        contact.setPhone("9876543210");
        assertEquals("9876543210", contact.getPhone());
    }

    @Test
    void testSetPhonenull() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setPhone(null));
    }
    
    @Test
    void testSetPhoneShort() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setPhone("123456789"));
    }
    
    @Test
    void testSetPhoneLong() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setPhone("12345678901"));
    }
    
    @Test
    void testSetPhoneNonNumeric() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setPhone("abc1234567"));
    }

    // address //
    @Test
    void testSetAddressValid() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        contact.setAddress("456 Oak Ave");
        assertEquals("456 Oak Ave", contact.getAddress());
    }

    @Test
    void testSetAddressNull() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setAddress(null));
    }
    
    @Test
    void testSetAddressEmpty() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setAddress(""));
    }
    
    @Test
    void testSetAddressLong() {
        Contact contact = new Contact("12345", "John", "Doe", "1234567890", "123 Main St");
        assertThrows(IllegalArgumentException.class, () -> contact.setAddress("This address is way too long and exceeds the thirty character limit"));
    }
}