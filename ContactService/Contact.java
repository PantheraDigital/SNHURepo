package ContactService;

public class Contact {

    private final String contactID;
    private String firstName;
    private String lastName;
    private String phone;
    private String address;

    public Contact(String contactID, String firstName, String lastName, String phone, String address) {
        if (contactID == null || contactID.trim().isEmpty() || contactID.length() > 10) {
            throw new IllegalArgumentException("Contact ID cannot be null, empty, or longer than 10 characters.");
        }
        this.contactID = contactID;
        setFirstName(firstName);
        setLastName(lastName);
        setPhone(phone);
        setAddress(address);
    }

    public String getContactID() {
        return contactID;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        if (firstName == null || firstName.trim().isEmpty() || firstName.length() > 10) {
            throw new IllegalArgumentException("First name cannot be null, empty, or longer than 10 characters.");
        }
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        if (lastName == null || lastName.trim().isEmpty() || lastName.length() > 10) {
            throw new IllegalArgumentException("Last name cannot be null, empty, or longer than 10 characters.");
        }
        this.lastName = lastName;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        if (phone == null || !phone.matches("\\d{10}")) {
            throw new IllegalArgumentException("Phone number must be exactly 10 digits and cannot be null.");
        }
        this.phone = phone;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        if (address == null || address.trim().isEmpty() || address.length() > 30) {
            throw new IllegalArgumentException("Address cannot be null, empty, or longer than 30 characters.");
        }
        this.address = address;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Contact contact = (Contact) o;
        return contactID.equals(contact.contactID) && firstName.equals(contact.getFirstName()) && lastName.equals(contact.getLastName()) && phone.equals(contact.getPhone()) && address.equals(contact.getAddress());
    }

    @Override
    public int hashCode() {
        return contactID.hashCode();
    }
}